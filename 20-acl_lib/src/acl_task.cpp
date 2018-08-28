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
#include "acl_task.h"
#include "acl_msgqueue.h"

#ifdef WIN32
#include<process.h>
#endif


typedef struct tagTaskParam
{
    void * pContent;
    u32 dwContentLen;
    u32 dwReserved;
    void *(*pTaskRunning)(void *);
}TTASK_PARAM;


ACL_API int aclCreateThread_b(PTACL_THREAD ptAclThread, PTTHREAD_PARAM ptThreadParam, PF_THREAD_ENTRY pfTaskEntry,void * pTaskParam)
{
    CHECK_NULL_RET_INVALID(ptAclThread)

#ifdef WIN32
    // Create thread
    ptAclThread->hThread  = (HANDLE)_beginthreadex( NULL, 
    ptThreadParam ? ptThreadParam->dwStackSize : 0, 
    pfTaskEntry, 
    pTaskParam,
    ptThreadParam ? ptThreadParam->nThreadRun : 0,
    &ptAclThread->dwThreadID);

#elif defined (_LINUX_)
    if(pthread_create(&ptAclThread->hThread, NULL, pfTaskEntry, pTaskParam))
    {  
        return ACL_ERROR_FAILED;
    }  
#endif
    return 0;
}

ACL_API int aclCreateThread(PTACL_THREAD ptAclThread, PF_THREAD_ENTRY pfTaskEntry,void * pTaskParam)
{
    PTTHREAD_PARAM ptThreadParam = NULL;
	CHECK_NULL_RET_INVALID(ptAclThread)

    return aclCreateThread_b(ptAclThread, ptThreadParam, pfTaskEntry, pTaskParam);
}

ACL_API int aclDestoryThread(H_ACL_THREAD hThread)
{
#ifdef WIN32
    CHECK_NULL_RET_INVALID(hThread)
    if (CloseHandle(hThread))
    {
        return 0;
    }
#elif defined(_LINUX_)
//linux���߳���Դ������ʱ�����
#endif
    return ACL_ERROR_FAILED;
}