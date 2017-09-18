#pragma once

#include <dxgi1_4.h>
#include <d3d12.h>
#include <atlbase.h>

#include "../Swapchain.hpp"

namespace te
{
	namespace gr
	{
		namespace d12
		{
			class D12Device;

			class D12Swapchain : public Swapchain
			{
			private:
				CComPtr<IDXGISwapChain3> m_SwapChain;

			public:
				D12Swapchain(D12Device* Dev, SwapchainDesc& Desc);
				~D12Swapchain();
				
				Result Initialize();

				void Present() override;
				void Resize() override;
				std::int32_t GetCurrentIndex() override;	
			};
		}
	}
}