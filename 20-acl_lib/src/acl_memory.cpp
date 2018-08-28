//******************************************************************************
//ģ����	�� acl_memory
//�ļ���	�� acl_memory.h
//����	�� zcckm
//�汾	�� 1.0
//�ļ�����˵��:
//ACL�ڴ����
//------------------------------------------------------------------------------
//�޸ļ�¼:
//2015-01-19 zcckm ����
//******************************************************************************
#include "acl_memory.h"
#include <malloc.h>
#include <memory.h>
#include "acl_common.h"
void * aclMalloc(int nSize)
{
    return malloc(nSize);
}

void * aclMallocClr(int nSize)
{
    void * pAlloc = malloc(nSize);
    memset(pAlloc,0,nSize);
    return pAlloc;
}

void aclFree(void * memory)
{
    if (memory)
    {
        free(memory);
        memory = NULL;
    }
}

#ifdef  _MSC_VER

#endif