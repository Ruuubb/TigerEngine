#pragma once

#include "../Instance.hpp"

namespace te
{
	namespace gr
	{
		namespace vul
		{
			class Instance : public te::gr::Instance
			{
			private:

			public:
				Result EnumerateAdapters() override;
				Result CreateDevice() override;

			private:
			};
		}
	}
}