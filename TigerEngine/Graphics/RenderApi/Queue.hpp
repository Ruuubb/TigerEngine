#pragma once

#include "Result.hpp"

namespace te
{
	namespace gr
	{
		struct QueueDesc;

		class Queue
		{
		private:

		public:
			virtual ~Queue() = 0 {};
		
			virtual Result Submit() = 0;
			virtual Result Signal() = 0;

		protected:
			Queue() {};

		private:

		};
	}
}