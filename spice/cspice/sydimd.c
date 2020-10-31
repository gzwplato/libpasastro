/* sydimd.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure            SYDIMD ( Return the dimension of a symbol ) */
integer sydimd_(char *name__, char *tabsym, integer *tabptr, doublereal *
	tabval, ftnlen name_len, ftnlen tabsym_len)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    integer nsym;
    extern integer cardc_(char *, ftnlen);
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern integer bsrchc_(char *, integer *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    integer locsym;
    extern logical return_(void);

/* $ Abstract */

/*     Return the dimension of a particular symbol in a double precision */
/*     symbol table. If the symbol is not found, the function returns the */
/*     value zero. */

/* $ Disclaimer */

/*     THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE */
/*     CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S. */
/*     GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE */
/*     ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE */
/*     PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS" */
/*     TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY */
/*     WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A */
/*     PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC */
/*     SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE */
/*     SOFTWARE AND RELATED MATERIALS, HOWEVER USED. */

/*     IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA */
/*     BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT */
/*     LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND, */
/*     INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS, */
/*     REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE */
/*     REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY. */

/*     RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF */
/*     THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY */
/*     CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE */
/*     ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE. */

/* $ Required_Reading */

/*     SYMBOLS */

/* $ Keywords */

/*     SYMBOLS */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     NAME       I   Name of the symbol whose dimension is desired. */
/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL    I/O  Components of the symbol table. */

/*     The function returns the dimension of the symbol NAME. If NAME is */
/*     not in the symbol table, the function returns the value zero. */

/* $ Detailed_Input */

/*     NAME       is the name of the symbol whose dimension is to be */
/*                returned. If the symbol is not in the symbol table, the */
/*                function returns the value zero. This function is case */
/*                sensitive, NAME must match a symbol exactly. */

/*     TABSYM, */
/*     TABPTR, */
/*     TABVAL      are the components of a double precision symbol table. */
/*                 The table may or may not contain the symbol NAME. */

/* $ Detailed_Output */

/*     The function returns the dimension of the symbol NAME. The */
/*     dimension of a symbol is the number of values associated with */
/*     that symbol. If NAME is not in the symbol table, the function */
/*     returns the value zero. */

/* $ Parameters */

/*     None. */

/* $ Files */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Particulars */

/*    None. */

/* $ Examples */

/*     The contents of the symbol table are: */

/*        DELTA_T_A -->   32.184 */
/*        K         -->    1.657D-3 */
/*        MEAN_ANOM -->    6.239996D0 */
/*                         1.99096871D-7 */


/*     Let NUMVAL be equal to the dimension of the symbols in the table. */
/*     The following code returns the values of NUMVAL indicated in the */
/*     table. */

/*     NUMVAL = SYDIMD ( 'MEAN_ANOM',   TABSYM, TABPTR, TABVAL ) */
/*     NUMVAL = SYDIMD ( 'K',           TABSYM, TABPTR, TABVAL ) */
/*     NUMVAL = SYDIMD ( 'DELTA_T_A',   TABSYM, TABPTR, TABVAL ) */
/*     NUMVAL = SYDIMD ( 'BODY10_AXES', TABSYM, TABPTR, TABVAL ) */

/*     ----SYMBOL----------NUMVAL------ */
/*     | MEAN_ANOM    |       2       | */
/*     | K            |       1       | */
/*     | DELTA_T_A    |       1       | */
/*     | BODY10_AXES  |       0       | */
/*     -------------------------------- */

/*     Note that the dimension of "BODY10_AXES" is zero. This is due to */
/*     the fact that "BODY10_AXES" is not in the symbol table. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     H.A. Neilan     (JPL) */
/*     I.M. Underwood  (JPL) */

/* $ Version */

/* -     SPICELIB Version 1.1.0, 17-MAY-1994 (HAN) */

/*        If the value of the function RETURN is TRUE upon execution of */
/*        this module, this function is assigned a default value of */
/*        either 0, 0.0D0, .FALSE., or blank depending on the type of */
/*        the function. */

/* -     SPICELIB Version 1.0.1, 10-MAR-1992 (WLT) */

/*         Comment section for permuted index source lines was added */
/*         following the header. */

/* -     SPICELIB Version 1.0.0, 31-JAN-1990 (IMU) (HAN) */

/* -& */
/* $ Index_Entries */

/*     fetch the dimension of a symbol */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Standard SPICE error handling. */

    if (return_()) {
	ret_val = 0;
	return ret_val;
    } else {
	chkin_("SYDIMD", (ftnlen)6);
    }

/*     How many symbols to start with? */

    nsym = cardc_(tabsym, tabsym_len);

/*     Is this symbol even in the table? */

    locsym = bsrchc_(name__, &nsym, tabsym + tabsym_len * 6, name_len, 
	    tabsym_len);

/*     If it's not in the table, return zero. Otherwise, look up */
/*     the dimension directly. */

    if (locsym == 0) {
	ret_val = 0;
    } else {
	ret_val = tabptr[locsym + 5];
    }
    chkout_("SYDIMD", (ftnlen)6);
    return ret_val;
} /* sydimd_ */
