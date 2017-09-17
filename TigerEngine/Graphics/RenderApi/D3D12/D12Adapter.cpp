#include "D12Adapter.hpp"

namespace te
{
	namespace gr
	{
		namespace d12
		{
			D12Adapter::D12Adapter(std::string Desc, size_t VideoMemory, size_t SystemMemory, size_t SharedMemory, uint32_t VendorID, uint32_t DeviceID, bool Remote, IDXGIAdapter2* RawAdapter, D3D_FEATURE_LEVEL FeatureLevel, bool SupportsApi) :
				te::gr::Adapter(Desc, VideoMemory, SystemMemory, SharedMemory, VendorID, DeviceID, Remote, SupportsApi),
				m_Adapter(RawAdapter),
				m_FeatureLevel(FeatureLevel)
			{
				

			}

			D12Adapter::~D12Adapter()
			{

			}

			IDXGIAdapter2* D12Adapter::GetAdapter() const
			{
				return m_Adapter;
			}

			D3D_FEATURE_LEVEL D12Adapter::GetFeatureLevel() const
			{
				return m_FeatureLevel;
			}

		}
	}
}