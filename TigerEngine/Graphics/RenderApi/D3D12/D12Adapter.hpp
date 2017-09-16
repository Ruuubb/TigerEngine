#pragma once

#include <dxgi1_4.h>
#include <atlbase.h>

#include "../Adapter.hpp"

namespace te
{
	namespace gr
	{
		namespace d12
		{
			class D12Adapter : public te::gr::Adapter
			{
			private:
				CComPtr<IDXGIAdapter2> m_Adapter;

			public:
				D12Adapter(std::string Desc, size_t VideoMemory, size_t SystemMemory, size_t SharedMemory, uint32_t VendorID, uint32_t DeviceID, bool Remote, IDXGIAdapter2* RawAdapter);
				~D12Adapter() override;

				IDXGIAdapter2* GetAdapter() const;


			};
		}
	}
}