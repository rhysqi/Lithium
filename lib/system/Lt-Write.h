#ifndef Lt_Write_H
#define Lt_Write_H

#ifdef _WIN32

int Lt_WriteFile(const char* FileName);
int Lt_ReadFile(const char* FileName);
int Lt_ExecFile(const char* FileName);

#endif /* _WIN32 */

#endif /* Lt_Write_H */