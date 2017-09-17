#include "Device.hpp"
#include "Adapter.hpp"

namespace te
{
	namespace gr
	{
		Device::Device(std::unique_ptr<Adapter> UsedAdapter) :
			m_Adapter(std::move(UsedAdapter))
		{
			
		}
	}
}
