#ifndef DUT_H_
#define DUT_H_
#include <systemc>
using namespace sc_core;

#include <cynw_p2p.h>

#include "filter_def.h"

class dut : public sc_module
{
public:
	sc_in_clk i_clk;
	sc_in<bool> i_rst;

	cynw_p2p<sc_dt::sc_uint<24>>::in i_rgb;
	cynw_p2p<sc_dt::sc_uint<32>>::out o_result;

	SC_HAS_PROCESS(dut);
	dut(sc_module_name n);
	~dut();

private:
	void do_filter();
	unsigned int buffer[9]; // data buffer
};
#endif
