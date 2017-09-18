#include "D12Device.hpp"
#include "D12Swapchain.hpp"
#include "D12Adapter.hpp"

namespace te
{
	namespace gr
	{
		namespace d12
		{

			D12Swapchain::D12Swapchain(D12Device* Dev, SwapchainDesc& Desc) :
				Swapchain(Dev, Desc)
			{

			}

			D12Swapchain::~D12Swapchain()
			{
				
			}

			Result D12Swapchain::Initialize()
			{
				DXGI_SWAP_CHAIN_DESC1 sd;
				ZeroMemory(&sd, sizeof(sd));
				sd.Width = w;
				sd.Height = h;
				sd.Format = Convert(mDesc.mFormat);
				sd.SampleDesc.Count = mDesc.mMultiSample.mCount;
				sd.SampleDesc.Quality = mDesc.mMultiSample.mQuality;
				sd.BufferUsage = 0; // Defaults to DXGI_USAGE_RENDER_TARGET_OUTPUT during creation.
				sd.BufferCount = mDesc.mBackBufferCount;
				sd.SwapEffect = Convert(mDesc.mSwapEffect);
				sd.Flags = 0; // DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING;

				return Result();
			}

			void D12Swapchain::Present()
			{

			}

			void D12Swapchain::Resize()
			{

			}

			std::int32_t D12Swapchain::GetCurrentIndex()
			{
				return 0;
			}

		}
	}
}