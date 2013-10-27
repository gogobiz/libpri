/* Arinc specific library issues */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include <stdarg.h>

#include "arinc.h"

struct arinc_object arinc_satcom_eqmtctrl;

char* arinc_satcom_eqmtctrl_current_time_in_responses_get(void);
void arinc_satcom_eqmtctrl_current_time_in_responses_set(char* x);

char* arinc_satcom_eqmtctrl_managed_object_info_in_responses_get(void);
void arinc_satcom_eqmtctrl_managed_object_info_in_responses_set(char *x);

int arinc_satcom_eqmtctrl_current_status_get(void);

/* current_time_in_responses; */
char* arinc_satcom_eqmtctrl_current_time_in_responses_get(void) {
        //      printf(DBGHEAD " arinc_satcom_eqmtctrl_current_time_in_responses_get =%s\n", DBGINFO, arinc_satcom_eqmtctrl.current_time_in_responses);
        return arinc_satcom_eqmtctrl.current_time_in_responses;
}
void arinc_satcom_eqmtctrl_current_time_in_responses_set(char *x) {
        //      printf( DBGHEAD " arinc_satcom_eqmtctrl_current_time_in_responses_set from: %s to: %s\n", DBGINFO, arinc_satcom_eqmtctrl.current_time_in_responses,x);
        arinc_satcom_eqmtctrl.current_time_in_responses = x;
}

/* managed_object_info_in_responses; */
char* arinc_satcom_eqmtctrl_managed_object_info_in_responses_get(void){
        //      printf(DBGHEAD " arinc_satcom_eqmtctrl_managed_object_info_in_responses_get =%s\n", DBGINFO, arinc_satcom_eqmtctrl.managed_object_info_in_responses);
        return arinc_satcom_eqmtctrl.managed_object_info_in_responses;
}

void arinc_satcom_eqmtctrl_managed_object_info_in_responses_set(char *x){
        //      printf( DBGHEAD " arinc_managed_object_info_in_responses_set from: %s to: %s\n", DBGINFO, arinc_satcom_eqmtctrl.managed_object_info_in_responses,x);
        arinc_satcom_eqmtctrl.managed_object_info_in_responses = x;
}

int arinc_satcom_eqmtctrl_current_status_get(void) {
	//  printf(DBGHEAD " arinc_satcom_eqmtctrl_current_status_get =%d\n", DBGINFO, arinc_satcom_eqmtctrl.current_status);
	return arinc_satcom_eqmtctrl.current_status;
}

int arinc_satcom_eqmtctrl_init(void) {

	arinc_satcom_eqmtctrl_current_status_set(0);
	arinc_satcom_eqmtctrl_poll_interval_set(0);
	arinc_satcom_eqmtctrl_current_time_in_responses_set("false");
	arinc_satcom_eqmtctrl_managed_object_info_in_responses_set("false");
	//arinc_satcom_config_load();
	return 0;
}

void arinc_satcom_eqmtctrl_current_status_set(int x) {
	arinc_satcom_eqmtctrl.current_status = x;
}

void arinc_satcom_eqmtctrl_poll_interval_set(int x) {
        arinc_satcom_eqmtctrl.poll_interval = x;
}


