#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <assert.h>

bool FuzzMe(const uint8_t *Data, size_t DataSize) {
	uint8_t max2= 10;
	for(unsigned i=0;i<DataSize;i++)
	{
		if(max2<Data[i])
		{
			max2=Data[i];
		}
	}
	size_t i=0;
	while(i<1000)
	{
		if(Data[i]==max2) return true;
		i++;
	}

  return false;

}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  FuzzMe(Data, Size);
  return 0;
}