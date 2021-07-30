/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : threading_alt.h
  * @author  MCD Application Team
  * @brief   template header file to be included the threading_alt.c

 ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/*
 * this files defines the mbedtls_threading_mutex_t data type used by the
 * mbedtls_mutex_xxx() API.
 * this file is included in the "threadind_alt_template.c", thus it should be
 * copied under the project Inc directory and renamed "thredading_alt.h"
 */

#ifndef MBEDTLS_THREADING_ALT_H
#define MBEDTLS_THREADING_ALT_H

#ifdef __cplusplus
extern "C" {
#endif
#include "mbedtls/platform.h"

#define MBEDTLS_ERR_THREADING_FEATURE_UNAVAILABLE         -0x001A  /**< The selected feature is not available. */
#define MBEDTLS_ERR_THREADING_BAD_INPUT_DATA              -0x001C  /**< Bad input parameters to function. */
#define MBEDTLS_ERR_THREADING_MUTEX_ERROR                 -0x001E  /**< Locking / unlocking / free failed with error code. */

#include "cmsis_os.h"
typedef struct {
#if (osCMSIS < 0x20000U)
     osMutexId mutex_id;
     osStatus status;
#else
     osMutexId_t mutex_id;
     osStatus_t status;
#endif

} mbedtls_threading_mutex_t;

void cmsis_os_mutex_init( mbedtls_threading_mutex_t *mutex );
void cmsis_os_mutex_free( mbedtls_threading_mutex_t *mutex );
int cmsis_os_mutex_lock( mbedtls_threading_mutex_t *mutex );
int cmsis_os_mutex_unlock( mbedtls_threading_mutex_t *mutex );

#ifdef __cplusplus
}
#endif

#endif /* MBEDTLS_THREADING_ALT_H */
