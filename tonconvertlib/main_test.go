package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestAddrConvert(t *testing.T) {

	addr_raw := "-1:3333333333333333333333333333333333333333333333333333333333333333"
	addr_hr := "Uf8zMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMxYA"
	addr_hr_bounce := "Ef8zMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzM0vF"

	result_addr_hr := convert_to_human_readable(addr_raw, false)
	assert.Equal(t, result_addr_hr, addr_hr)

	result_addr_hr_bounce := convert_to_human_readable(addr_raw, true)
	assert.Equal(t, result_addr_hr_bounce, addr_hr_bounce)

	result_addr_raw_one := convert_to_raw(addr_hr)
	assert.Equal(t, result_addr_raw_one, addr_raw)

	result_addr_raw_two := convert_to_raw(addr_hr_bounce)
	assert.Equal(t, result_addr_raw_two, addr_raw)
}
