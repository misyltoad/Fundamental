#ifndef FUNDAMENTAL_DEFINITIONS_H
#define FUNDAMENTAL_DEFINITIONS_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef _DEBUG
#define FUNDAMENTAL_DEBUG
#endif

#ifdef __cplusplus
#define nomangle extern "C"
#define startcblock extern "C" \
	{
#define endcblock }

#else
#define nomangle
#define startcblock
#define endcblock
#endif


#ifdef __cplusplus
}
#endif

#endif