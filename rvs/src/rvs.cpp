//============================================================================
// Name        : rvs.cpp
// Author      : HDL-DH
// Version     :
// Copyright   : (c) 2018
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include <dlfcn.h>

#include "rvsif0.h"
#include "rvsif1.h"
#include "rvsmodule.h"


using namespace std;


int main(int Argc, char**Argv) {
	cout << "Hello from RVS..." << endl; // prints !!!Hello World!!!



	rvsmodule* module = rvsmodule::create("libgpup.so.1");
	rvsif0* pif0 = (rvsif0*)module->get_interface(0);


	fprintf(stdout, "Module: %s\n", pif0->get_name() );

	fprintf(stdout, "Description: %s\n", pif0->get_description() );

	rvsmodule::destroy(module);

	return 0;
}




