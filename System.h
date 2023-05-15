#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <systemc>
using namespace sc_core;

#include "Testbench.h"

#include "dut_wrap.h"

class System : public sc_module
{
public:
	SC_HAS_PROCESS(System);
	System(sc_module_name n, std::string input_bmp, std::string output_bmp);
	~System();

private:
	Testbench tb;

	dut_wrapper dut;

	sc_clock clk;
	sc_signal<bool> rst;

	cynw_p2p<sc_dt::sc_uint<24>> rgb;
	cynw_p2p<sc_dt::sc_uint<32>> result;

	std::string _output_bmp;
};
#endif
