package main

import "C"

import (
	"encoding/hex"
	"fmt"
	"strconv"
	"strings"

	"github.com/xssnick/tonutils-go/address"
)

func main() {}

//export convert_to_human_readable_c
func convert_to_human_readable_c(addr string) *C.char {
	return C.CString(convert_to_human_readable(addr, false))
}

//export convert_to_human_readable_bounceable_c
func convert_to_human_readable_bounceable_c(addr string) *C.char {
	return C.CString(convert_to_human_readable(addr, true))
}

//export convert_to_raw_c
func convert_to_raw_c(addr string) *C.char {
	return C.CString(convert_to_raw(addr))
}

func convert_to_human_readable(addr string, bounce bool) string {
	addr_split := strings.Split(addr, ":")
	if len(addr_split) != 2 {
		return ""
	}

	workchain, err := strconv.Atoi(addr_split[0])
	if err != nil {
		return ""
	}

	decoded, err := hex.DecodeString(addr_split[1])
	if err != nil {
		return ""
	}

	a := address.NewAddress(byte(0), byte(workchain), decoded)
	a = a.Bounce(bounce)
	return a.String()
}

func convert_to_raw(addr string) string {
	e, err := address.ParseAddr(addr)
	if err != nil {
		return ""
	}
	return fmt.Sprintf("%v:%v", e.Workchain(), hex.EncodeToString(e.Data()))
}
