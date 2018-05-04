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
//#include "gpup.h"
#include "rvsmodule.h"

using namespace std;

typedef int (*t_libmain_func)(int, char**);
int rvs_module_init_interface0(void* pLib, RVSIF0* pIF);


int main(int Argc, char**Argv) {
	cout << "Hello from RVS..." << endl; // prints !!!Hello World!!!

	RVSIF0 if0;
//	RVSIF1 if1;

	void *lib_handle;


	lib_handle = dlopen("libgpup.so.1", RTLD_LAZY);

	if (!lib_handle)
	{
	   fprintf(stdout, "%s\n", dlerror());
	   return 1;
	}


	if( rvs_module_init_interface0(lib_handle, &if0))
	{
		   fprintf(stdout, "Could not load IF0\n");
		   return 1;
	}

	int major;
	int minor;
	int rev;

	(*if0.rvs_module_get_version)(&major, &minor, &rev);

	fprintf(stdout, "Module: %s\n", (*if0.rvs_module_get_name)() );

	fprintf(stdout, "Description: %s\n", (*if0.rvs_module_get_description)() );

	dlclose(lib_handle);

	return 0;
}


int rvs_module_init_interface0(void* pLib, RVSIF0* pIF)
{
	char *error;

	if (!pLib)
	{
	   fprintf(stdout, "Module not loaded\n" );
	   return 1;
	}

	pIF->rvs_module_get_version = (t_voidintpintpintp)(dlsym(pLib, "rvs_module_get_version"));
	if ((error = dlerror()) != NULL)
	{
	   fprintf(stdout, "%s\n", error);
	   return 1;
	}

	pIF->rvs_module_get_name = (t_charpvoid)(dlsym(pLib, "rvs_module_get_name"));
	if ((error = dlerror()) != NULL)
	{
	   fprintf(stdout, "%s\n", error);
	   return 1;
	}

	pIF->rvs_module_get_description = (t_charpvoid)(dlsym(pLib, "rvs_module_get_description"));
	if ((error = dlerror()) != NULL)
	{
	   fprintf(stdout, "%s\n", error);
	   return 1;
	}

	pIF->rvs_module_has_interface = (t_intint)(dlsym(pLib, "rvs_module_has_interface"));
	if ((error = dlerror()) != NULL)
	{
	   fprintf(stdout, "%s\n", error);
	   return 1;
	}


	return 0;
}


