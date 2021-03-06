/*
 *  CUnit - A Unit testing framework library for C.
 *  Copyright (C) 2001  Anil Kumar
 *  Copyright (C) 2004  Anil Kumar, Jerry St.Clair
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 *  Contains Interface to Run tests.
 *
 *  Created By     : Anil Kumar on ...(in month of Aug 2001)
 *  Last Modified  : 09/Aug/2001
 *  Comment        : Contains generic run tests interface which can be used
 *                   be used for any type of frontend interface framework.
 *  EMail          : aksaharan@yahoo.com
 *
 *  Last Modified  : 24/Nov/2001
 *  Comment        : Added Handler for Group Initialization failure condition.
 *  EMail          : aksaharan@yahoo.com
 *
 *  Last Modified  : 5-Aug-2004 (JDS)
 *  Comment        : New interface.  Since these should be internal functions,
 *                   no support for deprecated version 1 names provided now,
 *                   eliminated global variables for current test & suite,
 *                   moved (renamed) _TestResult here from TestDB.h.
 *  EMail          : jds2@users.sourceforge.net
 *
 *  Modified       : 5-Sep-2004 (JDS)
 *  Comment        : Added internal test interface.
 *  EMail          : jds2@users.sourceforge.net
 */

/** @file
 * Test run management functions (user interface).
 * The TestRun module implements functions supporting the running
 * of tests elements (suites and tests).  This includes functions for
 * running suites and tests, retrieving the number of tests/suites run,
 * and managing callbacks during the run process.
 * <P>The callback mechanism works as follows.  The CUnit runtime system
 * supports the registering and calling of functions at the start and end
 * of each test, when all tests are complete, and when a suite
 * initialialization function returns an error.  This allows clients to
 * perform actions associated with these events such as output formatting
 * and reporting.</P>
 */
/** @addtogroup Framework
 * @{
 */

#ifndef _CUNIT_TESTRUN_H
#define _CUNIT_TESTRUN_H

#include <private/cunit/CUnit.h>
#include <private/cunit/CUError.h>
#include <private/cunit/TestDB.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CU_FailureRecord type definition. */
/** Data type for holding assertion failure information (linked list). */
typedef struct CU_FailureRecord
{
  unsigned int  uiLineNumber;     /**< Line number of failure. */
  char*         strFileName;      /**< Name of file where failure occurred. */
  char*         strCondition;     /**< Test condition which failed. */
  CU_pTest      pTest;            /**< Test containing failure. */
  CU_pSuite     pSuite;           /**< Suite containing test having failure. */

  struct CU_FailureRecord* pNext; /**< Pointer to next record in linked list. */
  struct CU_FailureRecord* pPrev; /**< Pointer to previous record in linked list. */

} CU_FailureRecord;
typedef CU_FailureRecord* CU_pFailureRecord;  /**< Pointer to CU_FailureRecord. */

/* CU_RunSummary type definition. */
/** Data type for holding statistics and assertion failures for a test run. */
typedef struct CU_RunSummary
{
  unsigned int nSuitesRun;        /**< Number of suites completed during run. */
  unsigned int nSuitesFailed;     /**< Number of suites for which initialization failed. */
  unsigned int nTestsRun;         /**< Number of tests completed during run. */
  unsigned int nTestsFailed;      /**< Number of tests containing failed assertions. */
  unsigned int nAsserts;          /**< Number of assertions tested during run. */
  unsigned int nAssertsFailed;    /**< Number of failed assertions. */
  unsigned int nFailureRecords;   /**< Number of failure records generated. */
} CU_RunSummary;
typedef CU_RunSummary* CU_pRunSummary;  /**< Pointer to CU_RunSummary. */

/* Type Definitions for Message Handlers. */
/** Message handler called at the start of a test.
 * The parameters are the test and suite being run.
 * The test run is considered in progress when the
 * message handler is called.
 */
typedef void (*CU_TestStartMessageHandler)(const CU_pTest pTest, const CU_pSuite pSuite);
/** Message handler called at the completion of a test.
 * The parameters are the test and suite being run, plus
 * a pointer to the first failure record applicable to
 * this test.  If the test did not have any assertion
 * failures, pFailure will be NULL.
 * The test run is considered in progress when the
 * message handler is called.
 */
typedef void (*CU_TestCompleteMessageHandler)(const CU_pTest pTest, const CU_pSuite pSuite,
                                              const CU_pFailureRecord pFailure);
/** Message handler called at the completion of a test run.
 * The parameter is a pointer to the linked list holding
 * the failure records for the test run.
 * The test run is considered completed when the
 * message handler is called.
 */
typedef void (*CU_AllTestsCompleteMessageHandler)(const CU_pFailureRecord pFailure);
/** Message handler called when a suite initializer fails.
 * The test run is considered in progress when the
 * message handler is called.
 */
typedef void (*CU_SuiteInitFailureMessageHandler)(const CU_pSuite pSuite);

/* Get/Set functions for Message Handlers. */
void CU_set_test_start_handler(CU_TestStartMessageHandler pTestStartMessage);
void CU_set_test_complete_handler(CU_TestCompleteMessageHandler pTestCompleteMessage);
void CU_set_all_test_complete_handler(CU_AllTestsCompleteMessageHandler pAllTestsCompleteMessage);
void CU_set_suite_init_failure_handler(CU_SuiteInitFailureMessageHandler pSuiteInitFailureMessage);

CU_TestStartMessageHandler        CU_get_test_start_handler(void);
CU_TestCompleteMessageHandler     CU_get_test_complete_handler(void);
CU_AllTestsCompleteMessageHandler CU_get_all_test_complete_handler(void);
CU_SuiteInitFailureMessageHandler CU_get_suite_init_failure_handler(void);

/* Functions for running registered tests and suites. */
CU_ErrorCode CU_run_all_tests(void);
CU_ErrorCode CU_run_suite(CU_pSuite pSuite);
CU_ErrorCode CU_run_test(CU_pSuite pSuite, CU_pTest pTest);

/* Functions for getting information about the previous test run. */
unsigned int CU_get_number_of_suites_run(void);
unsigned int CU_get_number_of_suites_failed(void);
unsigned int CU_get_number_of_tests_run(void);
unsigned int CU_get_number_of_tests_failed(void);
unsigned int CU_get_number_of_asserts(void);
unsigned int CU_get_number_of_successes(void);
unsigned int CU_get_number_of_failures(void);
unsigned int CU_get_number_of_failure_records(void);
CU_pFailureRecord CU_get_failure_list(void);
CU_pRunSummary CU_get_run_summary(void);

/* Functions for internal & testing use. */
CU_pSuite CU_get_current_suite(void);
CU_pTest  CU_get_current_test(void);
BOOL      CU_is_test_running(void);
void      CU_clear_previous_results(void);

/* Assertion implementation function. */
BOOL CU_assertImplementation(BOOL bValue,
                             unsigned int uiLine,
                             char strCondition[],
                             char strFile[],
                             char strFunction[],
                             BOOL bFatal);

#ifdef USE_DEPRECATED_CUNIT_NAMES
typedef CU_FailureRecord  _TestResult;  /**< @deprecated Use CU_FailureRecord. */
typedef CU_pFailureRecord PTestResult;  /**< @deprecated Use CU_pFailureRecord. */
#endif  /* USE_DEPRECATED_CUNIT_NAMES */

#ifdef CUNIT_BUILD_TESTS
void test_cunit_TestRun(void);
#endif

#ifdef __cplusplus
}
#endif

#endif  /*  _CUNIT_TESTRUN_H  */

/** @} */
