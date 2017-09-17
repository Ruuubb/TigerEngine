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
				if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&m_DebugController))))
				{
					m_DebugController->EnableDebugLayer();
				}
				//////////////////////////////////////////////////////////////////////////		
			}

			D12Instance::~D12Instance()
			{

			}

			Result D12Instance::EnumerateAdapters(std::vector<std::unique_ptr<Adapter>>& Adapters)
			{
				//TODO change first flag depending on debug or not.
				HRESULT Res = CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&m_DxFactory));

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
							const D3D_FEATURE_LEVEL D12Levels[] =
							{
								D3D_FEATURE_LEVEL_12_1,
								D3D_FEATURE_LEVEL_12_0,
								D3D_FEATURE_LEVEL_11_1,
								D3D_FEATURE_LEVEL_11_0
							};

							const int LevelCount = sizeof(D12Levels) / sizeof(D3D_FEATURE_LEVEL);
							D3D_FEATURE_LEVEL HighestLevel = D3D_FEATURE_LEVEL(0);
							bool SupportApi = true;

							for (int i = 0; i < LevelCount; ++i)
							{
								if (SUCCEEDED(D3D12CreateDevice(Adapter2, D12Levels[i], _uuidof(ID3D12Device), nullptr)))
								{
									HighestLevel = D12Levels[i];
									break;
								}
							}

							if (HighestLevel == D3D_FEATURE_LEVEL(0))
								SupportApi = false;
							

							Adapters.emplace_back(new D12Adapter(std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(Desc2.Description), Desc2.DedicatedVideoMemory, Desc2.DedicatedSystemMemory,
								Desc2.SharedSystemMemory, Desc2.VendorId, Desc2.DeviceId, (Desc2.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) == 0, Adapter2, HighestLevel, SupportApi));
						}
					}

					Index++;
				}

				return Result();
			}		

			Result D12Instance::CreateDevice(std::unique_ptr<Adapter> UsedAdapter, Device** CreatedDevice)
			{
				*CreatedDevice = new D12Device(std::move(UsedAdapter));
				return (*CreatedDevice)->Initialize();
			}
		}
	}
}