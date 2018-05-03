/*
 * rvsmodule.h
 *
 *  Created on: Apr 27, 2018
 *      Author: ubuntu
 */

#ifndef RVSMODULE_H_
#define RVSMODULE_H_

extern "C"
{

extern void  rvs_module_get_version(int* Major, int* Minor, int* Revision);
extern char* rvs_module_get_name(void);
extern char* rvs_module_get_description(void);
extern int   rvs_module_has_interface(int InterfaceID);

extern int   rvs_module_init(void);
extern int   rvs_module_run(int Argc, char* Argv[]);
extern char* rvs_module_get_errstring(void);
extern int   rvs_module_get_errint(void);
extern int   rvs_module_terminate(void);

// define function pointer types to ease late binding usage
typedef void  (*t_voidintpintpintp)(int* Major, int* Minor, int* Revision);
typedef char* (*t_charpvoid)(void);
typedef int   (*t_intvoid)(void);
typedef int   (*t_intint)(int);
typedef int   (*t_intintcharpp)(int Argc, char* Argv[]);

typedef struct
{
	t_voidintpintpintp rvs_module_get_version;
	t_charpvoid        rvs_module_get_name;
	t_charpvoid        rvs_module_get_description;
	t_intint           rvs_module_has_interface;
} RVSIF0;

typedef struct
{
	t_intvoid         rvs_module_init;
	t_intintcharpp    rvs_module_run;
	t_charpvoid       rvs_module_get_errstring;
	t_intvoid         rvs_module_get_errint;
	t_intvoid         rvs_module_terminate;

} RVSIF1;

}


#endif /* RVSMODULE_H_ */
