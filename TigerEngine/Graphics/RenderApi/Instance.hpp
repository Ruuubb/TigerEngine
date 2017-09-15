#pragma once

#include "Result.hpp"

namespace te
{
	namespace gr
	{
		class Instance
		{
		public:
			Result EnumerateAdapters();
			Result CreateDevice();
	
		};
	}
}