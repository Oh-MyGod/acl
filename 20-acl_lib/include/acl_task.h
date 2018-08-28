//******************************************************************************
//ģ����	�� acl_task
//�ļ���	�� acl_task.h
//����	�� zcckm
//�汾	�� 1.0
//�ļ�����˵��:
//���߳̽ӿڽ��з�װ,����ֲ����ӦOSʱ��Ҫʵ���б���ĺ���
//------------------------------------------------------------------------------
//�޸ļ�¼:
//2014-12-30 zcckm ����
//******************************************************************************
#ifndef _ACL_TASK_H_
#define _ACL_TASK_H_

#include "acl_common.h"


#define WAIT_FOR_EXIT(v) v = E_TASK_ASK_FOR_EXIT; while(E_TASK_ALREADY_EXIT != v){aclDelay(1);} 

// #ifdef __cplusplus
// extern "C" {
// #endif //extern "C"

ACL_API int aclCreateThread_b(PTACL_THREAD ptAclThread, PTTHREAD_PARAM ptThreadParam, PF_THREAD_ENTRY pfTaskEntry,void * pTaskParam);
ACL_API int aclDestoryThread(H_ACL_THREAD hThread);
ACL_API int aclCreateThread(PTACL_THREAD ptAclThread, PF_THREAD_ENTRY pfTaskEntry,void * pTaskParam);

// #ifdef __cplusplus
// }
// #endif //extern "C"

#endif

