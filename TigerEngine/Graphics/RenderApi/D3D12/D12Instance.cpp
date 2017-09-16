#include <cstdint>
#include <locale> 
#include <codecvt>

#include "D12Instance.hpp"
#include "D12Device.hpp"

#pragma comment (lib, "d3d12.lib")
#pragma comment (lib, "DXGI.lib")

namespace te
{
	namespace gr
	{
		namespace d12
		{
			D12Instance::D12Instance()
			{
				//////////////////////////////////////////////////////////////////////////
				//TODO debug shit
				uint32_t Flags = DXGI_CREATE_FACTORY_DEBUG;
				if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&m_DebugController))))
				{
					m_DebugController->EnableDebugLayer();
				}
				//////////////////////////////////////////////////////////////////////////

				HRESULT Res = CreateDXGIFactory2(Flags, IID_PPV_ARGS(&m_DxFactory));
			}

			D12Instance::~D12Instance()
			{

			}

			Result D12Instance::EnumerateAdapters(std::vector<std::unique_ptr<Adapter>>& Adapters)
			{
				IDXGIAdapter1* Adapter1;

				uint32_t Index = 0;
				while (SUCCEEDED(m_DxFactory->EnumAdapters1(Index, &Adapter1)))
				{
					IDXGIAdapter2* Adapter2;
					if (SUCCEEDED(Adapter1->QueryInterface(&Adapter2)))
					{
						DXGI_ADAPTER_DESC2 Desc2;
						if (SUCCEEDED(Adapter2->GetDesc2(&Desc2)))
						{
							Adapters.emplace_back(new D12Adapter(std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(Desc2.Description), Desc2.DedicatedVideoMemory, Desc2.DedicatedSystemMemory,
								Desc2.SharedSystemMemory, Desc2.VendorId, Desc2.DeviceId, (Desc2.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) == 0, Adapter2));
						}
					}

					Index++;
				}

				return Result();
			}
						


			Result D12Instance::CreateDevice(Adapter* UsedAdapter, Device** CreatedDevice)
			{
				D12Adapter* UsedD12Adapter = static_cast<D12Adapter*>(UsedAdapter);

				*CreatedDevice = new D12Device(UsedD12Adapter);


				return Result();
			}
		}
	}
}