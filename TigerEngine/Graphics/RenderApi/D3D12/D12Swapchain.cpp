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