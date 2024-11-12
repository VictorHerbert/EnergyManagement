/**
 * @brief The main DPM simulator program
 */

#include "inc/psm.h"
#include "inc/dpm_policies.h"
#include "inc/utilities.h"

#define MAX_FILENAME 256

int main(int argc, char *argv[]) {

    char fwl[MAX_FILENAME];
    psm_t psm;
    dpm_general_params gparams;
    dpm_timeout_params tparams;
    dpm_history_params hparams;
    dpm_policy_t sel_policy;

    if(!parse_args(argc, argv, fwl, &psm, &sel_policy, &gparams, &tparams, &hparams)) {
        printf("[error] reading command line arguments\n");
        return -1;
    }
    double max_timeout = tparams.timeout;
    //psm_print(psm);    

    if (gparams.verbose_level == CSV)
        printf("file,timeout,energy_without_dpm,energy_with_dpm\n");

    if(sel_policy == DPM_TIMEOUT)
        for(double timeout = 0; timeout < max_timeout; timeout += max_timeout/tparams.timeout_step){
            tparams.timeout = timeout;
            dpm_simulate(psm, sel_policy, gparams, tparams, hparams, "workloads/w1.txt");
            dpm_simulate(psm, sel_policy, gparams, tparams, hparams, "workloads/w2.txt");
            //printf("after-> %f\n", tparams.timeout);
        }
    else if(sel_policy == DPM_HISTORY){
        dpm_simulate(psm, sel_policy, gparams, tparams, hparams, "workloads/w2.txt");
    }
}
