#include "dezaemonSymbol.h"
#include "ioMapping.h"
#include "bios.h"
#include "baseActivity.h"
#include "kakushi.h"

static char MojiPalette01[] = {M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette02[] = {H_KO, H_NO, H_TA, H_HI, H_HA, H_TE, H_NN, H_SO, H_UU, H_KU, H_NN, K_SI, K_XU, K_NI, K_AA, H_WO, H_KA, H_XT, H_TE, H_II, H_TA, H_TA, H_KI, H_MA, H_KO, H_TO, H_NI, M_SP, M_SP  ,'\0' };
static char MojiPalette03[] = {M_SP, M_SP, K_DT, M_SP, M_SP, K_DT, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette04[] = {H_AA, H_RI, H_KA, H_TO, H_UU, H_KO, H_SA, H_II, H_MA, H_SU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette05[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette06[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette07[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette08[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, H_OO, H_SI, H_RA, H_SE, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette09[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette10[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette11[] = {M_SP, M_SP, M_SP, M_SP, K_DT, K_DT, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette12[] = {M_SP, M_SP, H_KO, H_KO, H_TE, K_TE, K_SA, K_EE, K_MO, K_NN, H_NO, M_04, H_XT, H_TU, H_NO, H_HI, H_MI, H_TU, H_WO, H_KO, H_UU, H_KA, H_II, H_SI, H_MA, H_SU, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette13[] = {M_SP, M_SP, K_DT, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette14[] = {M_01, M_PI, H_TO, H_KO, H_TA, H_KA, H_WA, H_KA, H_RA, H_NA, H_II, H_KE, H_TO, K_SO, K_BO, K_SU, K_RI, K_SU, K_TO, H_NO, H_II, H_TI, H_HU, H_KO, H_UU, H_KA, H_II, H_MR, M_SP  ,'\0' };
static char MojiPalette15[] = {M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, K_DM, K_DT, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette16[] = {M_02, M_PI, K_HA, K_XT, K_KU, K_AA, K_XT, K_HU, K_TE, K_BO, K_TA, H_NO, K_AA, K_TO, K_RE, K_SU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette17[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette18[] = {M_03, M_PI, H_TU, H_UU, H_SI, H_NN, H_KI, H_NO, H_UU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette19[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette20[] = {M_04, M_PI, H_TE, H_NN, H_SO, H_UU, H_KU, H_NN, K_SI, K_XU, K_NI, K_AA, H_HA, H_TU, H_HA, H_II, H_TI, H_XU, H_UU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette21[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette22[] = {H_NO, M_04, H_XT, H_TU, H_NO, H_YA, H_HA, H_II, H_HI, H_MI, H_TU, H_WO, H_TA, H_II, H_KO, H_UU, H_KA, H_II, H_SI, H_MA, H_SU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette23[] = {M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette24[] = {H_KA, H_NA, H_RI, H_YA, H_HA, H_II, H_TO, H_KO, H_RO, H_HA, H_HU, H_SE, H_TE, H_AA, H_RI, H_MA, H_SU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette25[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette26[] = {H_OO, H_TO, H_II, H_AA, H_WA, H_SE, H_NI, H_HA, H_II, H_XT, H_SA, H_II, H_OO, H_KO, H_TA, H_EE, H_TE, H_KI, H_MA, H_SE, H_NN, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };

static char MojiPalette31[] = {H_HI, H_MI, H_TU, M_04, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette32[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, K_DT, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette33[] = {H_TE, H_NN, H_SO, H_UU, H_KU, H_NN, K_SI, K_XU, K_NI, K_AA, H_WO, H_TU, H_KA, H_XT, H_TE, H_TN, K_TE, K_BO, K_TA, H_NO, H_YA, H_RI, H_TO, H_RI, H_KA, H_TE, H_KI, H_RU, H_MR  ,'\0' };
static char MojiPalette34[] = {M_SP, M_SP, M_SP, M_SP, K_DT, K_DT, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, K_DM, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, K_DT, M_SP, M_SP  ,'\0' };
static char MojiPalette35[] = {H_TU, H_MA, H_RI, H_TN, H_SI, H_HU, H_NN, H_TE, H_TU, H_KU, H_XT, H_TA, K_KE, K_BO, K_MU, H_WO, K_KO, K_NN, K_HI, K_XU, K_BO, K_TA, K_BO, H_TE, H_SU, H_II, H_TA, H_SI, M_SP  ,'\0' };
static char MojiPalette36[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette37[] = {H_TA, H_RI, H_TN, K_KA, K_SE, K_XT, K_TO, H_NI, H_TE, H_NN, H_SO, H_UU, H_SI, H_TA, H_RI, H_TE, H_KI, H_MA, H_SU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette38[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette39[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette40[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette41[] = {H_YO, H_UU, H_II, H_SU, H_RU, H_MO, H_NO, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette42[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, K_DM, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, K_DT, M_SP, K_DT, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette43[] = {H_TE, H_NN, H_SO, H_UU, H_KU, H_NN, K_SI, K_XU, K_NI, K_AA, H_TN, K_HA, K_SO, K_KO, K_NN, H_TN, H_KA, H_AA, H_RE, H_HA, H_NA, H_NN, H_KO, H_TE, H_MO, K_KE, K_BO, K_MU, M_SP  ,'\0' };
static char MojiPalette44[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, K_DT, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette45[] = {H_WO, H_TU, H_KU, H_RU, H_KO, H_TO, H_KA, H_TE, H_KI, H_RU, H_SI, H_TN, K_TE, K_BO, K_TA, H_NO, H_HO, H_SO, H_NN, H_MO, H_KA, H_NO, H_UU, H_TE, H_AA, H_RU, H_MR, M_SP, M_SP  ,'\0' };
static char MojiPalette46[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, K_DT, K_DT, M_SP, K_DT, M_SP  ,'\0' };
static char MojiPalette47[] = {H_SO, H_RE, H_NI, H_TN, M_0D, M_0E, M_0Z, M_0A, M_0E, M_0M, M_0O, M_0N, M_SP, M_0B, M_0I, M_0O, M_0S, M_SP, H_WO, H_TU, H_KA, H_EE, H_HA, H_TN, H_SI, H_HU, H_NN, H_TE, M_SP  ,'\0' };
static char MojiPalette48[] = {K_DM, M_SP, K_DT, M_SP, M_SP, M_SP, K_DT, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette49[] = {K_HU, K_RO, K_KU, K_RA, K_MI, K_NN, K_KU, H_MO, H_TE, H_KI, H_MA, H_SU, H_MR, M_0C, H_NO, H_TI, H_SI, H_KI, H_TO, H_KO, H_NN, H_KI, H_KA, H_AA, H_RE, H_HA, H_II, H_RO, M_SP  ,'\0' };
static char MojiPalette50[] = {M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette51[] = {H_II, H_RO, H_NA, H_MO, H_NO, H_KA, H_TU, H_KU, H_RE, H_RU, H_TE, H_SI, H_XO, H_UU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette52[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette53[] = {H_KO, H_KO, H_NI, H_KA, H_KA, H_RE, H_TA, H_HI, H_MI, H_TU, H_NI, H_KA, H_NN, H_SI, H_TE, H_NO, H_TO, H_II, H_AA, H_WA, H_SE, H_HA, H_TN, H_II, H_XT, H_SA, H_II, H_II, M_SP  ,'\0' };
static char MojiPalette54[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette55[] = {H_TA, H_SI, H_TE, H_OO, H_RI, H_MA, H_SE, H_NN, H_MR, H_TE, H_NN, H_WA, H_RE, H_NN, H_RA, H_KU, H_NA, H_TO, H_HA, H_KO, H_EE, H_NN, H_RI, H_XO, H_KU, H_TA, H_SA, H_II, H_MR  ,'\0' };
static char MojiPalette56[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };

static char MojiPalette61[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette62[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, H_AA, H_TO, H_KA, H_KI, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette63[] = {M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, K_DT, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette64[] = {H_TA, H_HA, H_TA, H_SA, H_NN, H_MR, H_KO, H_UU, H_RI, H_NN, H_SI, H_TE, H_KU, H_RE, H_TE, H_AA, H_RI, H_KA, H_TO, H_UU, H_KO, H_SA, H_II, H_MA, H_SU, H_MR, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette65[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette66[] = {H_SO, H_RE, H_NI, H_TN, M_0D, M_0E, M_0Z, M_0A, M_0E, M_0M, M_0O, M_0N, M_SP, M_0B, M_0I, M_0O, M_0S, M_SP, H_NO, H_KO, H_UU, H_KA, H_II, H_AA, H_RI, H_KA, H_TO, H_UU, M_SP  ,'\0' };
static char MojiPalette67[] = {K_DT, K_DT, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette68[] = {H_KO, H_SA, H_II, H_MA, H_SU, H_MR, H_TO, H_RE, H_KU, H_RA, H_II, H_NO, H_HI, H_TO, H_NI, H_HU, H_RE, H_TE, H_MO, H_RA, H_EE, H_RU, H_KA, H_WA, H_KA, H_RI, H_MA, H_SE, M_SP  ,'\0' };
static char MojiPalette69[] = {M_SP, K_DT, M_SP, K_DT, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette70[] = {H_NN, H_KA, H_TN, K_TE, K_SA, K_EE, K_MO, K_NN, H_WO, H_TU, H_KU, H_XT, H_TA, K_SU, K_TA, K_XT, K_HU, H_NI, H_TU, H_KU, H_XT, H_TE, H_MO, H_RA, H_EE, H_RU, H_NA, H_NN, M_SP  ,'\0' };
static char MojiPalette71[] = {M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette72[] = {H_TE, H_TN, H_SU, H_KO, H_II, H_KO, H_TO, H_TA, H_TO, H_OO, H_MO, H_II, H_MA, H_SU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette73[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette74[] = {K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette75[] = {H_SI, H_KA, H_II, H_SA, H_KU, H_HA, H_TN, H_TE, H_NN, H_SO, H_UU, H_KU, H_NN, K_SI, K_XU, K_NI, K_AA, M_02, H_WO, H_TU, H_KU, H_RU, M_K1, K_UU, K_SO, H_TE, H_SU, M_K2, M_SP  ,'\0' };
static char MojiPalette76[] = {M_SP, M_SP, M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette77[] = {H_YO, H_TE, H_II, H_TE, H_SU, H_MR, H_KO, H_RE, H_KA, H_RA, H_MO, H_HI, H_RO, K_BO, H_MI, H_NN, K_HU, K_X1, K_KU, K_TO, K_RI, K_BO, H_WO, H_YO, H_RO, H_SI, H_KU, H_OO, M_SP  ,'\0' };
static char MojiPalette78[] = {M_SP, K_DT, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette79[] = {H_NE, H_KA, H_II, H_II, H_TA, H_SI, H_MA, H_SU, H_MR, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette80[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette81[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette82[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette83[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette84[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette85[] = {M_0H, M_0I, M_0R, M_0O, M_0O, M_0M, M_0I, M_0N, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_02, M_02, M_SU, M_01, M_01, M_SU, M_00, M_09, M_SP, M_SP, M_SP  ,'\0' };
static char MojiPalette86[] = {M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP, M_SP  ,'\0' };

short KakushiInit(KakushiActivityWork *aw){
	cls();
	//print(0,1,"                      ");
	return false;
}

short KakushiUpdate(KakushiActivityWork *aw){
	unsigned short padTr = readTriggerPad();

	if(aw->Sx != 0x0FE && aw->Sx != 0x1FE && aw->Sx != 0x2FE) {
		aw->Sx++;
	}else{
		if(aw->Sx == 0x2FE && padTr & PADB){
			*((unsigned char *)BG3VBUFF) = 0xff; 
			return false;
		}
		if(padTr & PADB) aw->Sx++;
	}

	*((unsigned char *)BG3VBUFF) = aw->Sx; 

	if(aw->Sx == 0x00E) print(2,1,MojiPalette01);
	if(aw->Sx == 0x016) print(2,2,MojiPalette02);
	if(aw->Sx == 0x01E) print(2,3,MojiPalette03);
	if(aw->Sx == 0x026) print(2,4,MojiPalette04);
	if(aw->Sx == 0x02E) print(2,5,MojiPalette05);
	if(aw->Sx == 0x036) print(2,6,MojiPalette06);
	if(aw->Sx == 0x03E) print(2,7,MojiPalette07);
	if(aw->Sx == 0x046) print(2,8,MojiPalette08);
	if(aw->Sx == 0x04E) print(2,9,MojiPalette09);
	if(aw->Sx == 0x056) print(2,10,MojiPalette10);
	if(aw->Sx == 0x05E) print(2,11,MojiPalette11);
	if(aw->Sx == 0x066) print(2,12,MojiPalette12);
	if(aw->Sx == 0x06E) print(2,13,MojiPalette13);
	if(aw->Sx == 0x076) print(2,14,MojiPalette14);
	if(aw->Sx == 0x07E) print(2,15,MojiPalette15);
	if(aw->Sx == 0x086) print(2,16,MojiPalette16);
	if(aw->Sx == 0x08E) print(2,17,MojiPalette17);
	if(aw->Sx == 0x096) print(2,18,MojiPalette18);
	if(aw->Sx == 0x09E) print(2,19,MojiPalette19);
	if(aw->Sx == 0x0A6) print(2,20,MojiPalette20);
	if(aw->Sx == 0x0AE) print(2,21,MojiPalette21);
	if(aw->Sx == 0x0B6) print(2,22,MojiPalette22);
	if(aw->Sx == 0x0BE) print(2,23,MojiPalette23);
	if(aw->Sx == 0x0C6) print(2,24,MojiPalette24);
	if(aw->Sx == 0x0CE) print(2,25,MojiPalette25);
	if(aw->Sx == 0x0D6) print(2,26,MojiPalette26);
	if(aw->Sx == 0x0DE) print(2,27,"                             ");
	if(aw->Sx == 0x0E6) print(2,28,"                             ");
	if(aw->Sx == 0x0EE) print(2,29,"                             ");
	if(aw->Sx == 0x0F6) print(2,30,"                             ");
	if(aw->Sx == 0x0FE) print(2,31,"                             ");

	if(aw->Sx == 0x10E) print(2,1,MojiPalette31);
	if(aw->Sx == 0x116) print(2,2,MojiPalette32);
	if(aw->Sx == 0x11E) print(2,3,MojiPalette33);
	if(aw->Sx == 0x126) print(2,4,MojiPalette34);
	if(aw->Sx == 0x12E) print(2,5,MojiPalette35);
	if(aw->Sx == 0x136) print(2,6,MojiPalette36);
	if(aw->Sx == 0x13E) print(2,7,MojiPalette37);
	if(aw->Sx == 0x146) print(2,8,MojiPalette38);
	if(aw->Sx == 0x14E) print(2,9,MojiPalette39);
	if(aw->Sx == 0x156) print(2,10,MojiPalette40);
	if(aw->Sx == 0x15E) print(2,11,MojiPalette41);
	if(aw->Sx == 0x166) print(2,12,MojiPalette42);
	if(aw->Sx == 0x16E) print(2,13,MojiPalette43);
	if(aw->Sx == 0x176) print(2,14,MojiPalette44);
	if(aw->Sx == 0x17E) print(2,15,MojiPalette45);
	if(aw->Sx == 0x186) print(2,16,MojiPalette46);
	if(aw->Sx == 0x18E) print(2,17,MojiPalette47);
	if(aw->Sx == 0x196) print(2,18,MojiPalette48);
	if(aw->Sx == 0x19E) print(2,19,MojiPalette49);
	if(aw->Sx == 0x1A6) print(2,20,MojiPalette50);
	if(aw->Sx == 0x1AE) print(2,21,MojiPalette51);
	if(aw->Sx == 0x1B6) print(2,22,MojiPalette52);
	if(aw->Sx == 0x1BE) print(2,23,MojiPalette53);
	if(aw->Sx == 0x1C6) print(2,24,MojiPalette54);
	if(aw->Sx == 0x1CE) print(2,25,MojiPalette55);
	if(aw->Sx == 0x1D6) print(2,26,MojiPalette56);
	if(aw->Sx == 0x1DE) print(2,27,"                             ");
	if(aw->Sx == 0x1E6) print(2,28,"                             ");
	if(aw->Sx == 0x1EE) print(2,29,"                             ");
	if(aw->Sx == 0x1F6) print(2,30,"                             ");
	if(aw->Sx == 0x1FE) print(2,31,"                             ");

	if(aw->Sx == 0x20E) print(2,1,MojiPalette61);
	if(aw->Sx == 0x216) print(2,2,MojiPalette62);
	if(aw->Sx == 0x21E) print(2,3,MojiPalette63);
	if(aw->Sx == 0x226) print(2,4,MojiPalette64);
	if(aw->Sx == 0x22E) print(2,5,MojiPalette65);
	if(aw->Sx == 0x236) print(2,6,MojiPalette66);
	if(aw->Sx == 0x23E) print(2,7,MojiPalette67);
	if(aw->Sx == 0x246) print(2,8,MojiPalette68);
	if(aw->Sx == 0x24E) print(2,9,MojiPalette69);
	if(aw->Sx == 0x256) print(2,10,MojiPalette70);
	if(aw->Sx == 0x25E) print(2,11,MojiPalette71);
	if(aw->Sx == 0x266) print(2,12,MojiPalette72);
	if(aw->Sx == 0x26E) print(2,13,MojiPalette73);
	if(aw->Sx == 0x276) print(2,14,MojiPalette74);
	if(aw->Sx == 0x27E) print(2,15,MojiPalette75);
	if(aw->Sx == 0x286) print(2,16,MojiPalette76);
	if(aw->Sx == 0x28E) print(2,17,MojiPalette77);
	if(aw->Sx == 0x296) print(2,18,MojiPalette78);
	if(aw->Sx == 0x29E) print(2,19,MojiPalette79);
	if(aw->Sx == 0x2A6) print(2,20,MojiPalette80);
	if(aw->Sx == 0x2AE) print(2,21,MojiPalette81);
	if(aw->Sx == 0x2B6) print(2,22,MojiPalette82);
	if(aw->Sx == 0x2BE) print(2,23,MojiPalette83);
	if(aw->Sx == 0x2C6) print(2,24,MojiPalette84);
	if(aw->Sx == 0x2CE) print(2,25,MojiPalette85);
	if(aw->Sx == 0x2D6) print(2,26,MojiPalette86);
	if(aw->Sx == 0x2DE) print(2,27,"                             ");
	if(aw->Sx == 0x2E6) print(2,28,"                             ");
	if(aw->Sx == 0x2EE) print(2,29,"                             ");
	if(aw->Sx == 0x2F6) print(2,30,"                             ");
	if(aw->Sx == 0x2FE) print(22,31,"                            ");

	if(aw->Sx == 0x300) aw->Sx=0x000;

	if(padTr & PADX){
		*((unsigned char *)BG3VBUFF) = 0xff; 
		return false;
	}
	return true;
}
