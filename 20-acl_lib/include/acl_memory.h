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
#ifndef _ACL_MEMORY_H_
#define _ACL_MEMORY_H_

// #ifdef __cplusplus
// extern "C" {
// #endif //extern "C"


//�ڴ����
void * aclMalloc(int nSize);

void * aclMallocClr(int nSize);

void aclFree(void * memory);

// #ifdef __cplusplus
// }
// #endif //extern "C"

#endif