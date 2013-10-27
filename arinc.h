/* managed_object_info_in_responses */
/* managed_object_info_in_responses */

#define ARINC_EQMTCTRL_MAX_ATTRIBUTES 10
#define ARINC_EQMTCTRL_MAX_ERRORS 10

struct arinc_invocation {
    struct pri *ctrl;     	/* Equipment Controller pointer */
    int ir;                     /* Invocation Reference */
    int forceinvert;            /* ?? Force inversion of call number even if 0 */
    struct arinc_invocation *next;
    //int invoke_ID;
    int managed_object;
    int managed_object_instance;
    int century;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int event_type;
    int event_reply;
    int attrib[ARINC_EQMTCTRL_MAX_ATTRIBUTES];      /*  <<<< check usage in code*/
    int attrib_list[ARINC_EQMTCTRL_MAX_ATTRIBUTES]; /* requested attrib */
    int errorlist[ARINC_EQMTCTRL_MAX_ERRORS];
    int send_object_info_ie;         /* Whether or not to send the MANAGED_OBJECT_IN_RESPONSES */
    int send_time_ie;                /* Whether or not to send the CURRENT_TIME_IN_RESPONSES */
    int peerinvokestate;             /* Call state of peer as reported */
    int ourinvokestate;              /* Our invocation state */
    int sugcallstate;                /* Status call state */
    int newcall;                     /* ?? not sure if ARINC needs this but it is used */
    int request_timeout_index;       /* Request time-out index of scheduler array */
    //int t308_timedout;               /* Whether t308 timed out once */
    int acked;                       /* whether invocation was acked */
};

int arinc_satcom_eqmtctrl_init(void);

int arinc_satcom_eqmtctrl_current_status_get(void);
void arinc_satcom_eqmtctrl_current_status_set(int x);

int arinc_satcom_eqmtctrl_poll_interval_get(void);
void arinc_satcom_eqmtctrl_poll_interval_set(int x);

char* arinc_satcom_eqmtctrl_current_time_in_responses_get(void);
void arinc_satcom_eqmtctrl_current_time_in_responses_set(char *x);

char* arinc_satcom_eqmtctrl_managed_object_info_in_responses_get(void);
void arinc_satcom_eqmtctrl_managed_object_info_in_responses_set(char *x);

typedef struct arinc_object {
        int current_status;
        int poll_interval;
        char* current_time_in_responses;
        char* managed_object_info_in_responses;
} arinc_object;
