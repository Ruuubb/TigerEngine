#include "../Adapter.hpp"
#include "D12Device.hpp"
#include "D12Adapter.hpp"

namespace te
{
	namespace gr
	{
		namespace d12
		{	
			D12Device::D12Device(std::unique_ptr<Adapter> UsedAdapter) :
				Device(std::move(UsedAdapter))
			{

			}

			Result D12Device::Initialize()
			{
				D12Adapter* UsedAdapter = static_cast<D12Adapter*>(m_Adapter.get());

				if (FAILED(D3D12CreateDevice(UsedAdapter->GetAdapter(), UsedAdapter->GetFeatureLevel(), IID_PPV_ARGS(&m_Device))))
				{
					int x = 2;
				}



				return Result();
			}

			Result D12Device::Shutdown()
			{
				return Result();
			}

			Result D12Device::CreateVertexBuffer()
			{
				return Result();
			}

			Result D12Device::CreateIndexBuffer()
			{
				return Result();
			}

			Result D12Device::CreateConstantBuffer()
			{
				return Result();
			}

			Result D12Device::CreateCommandPool()
			{
				return Result();
			}

			Result D12Device::CreateCommandBuffer()
			{
				return Result();
			}

			Result D12Device::CreateQueue()
			{
				return Result();
			}

			Result D12Device::CreateFence()
			{
				return Result();
			}

			Result D12Device::CreateSwapchain()
			{
				return Result();
			}

			Result D12Device::CreateRenderPass()
			{
				return Result();
			}

			Result D12Device::CreatePipeline()
			{
				return Result();
			}

			Result D12Device::CreateFrameBuffer()
			{
				return Result();
			}

			Result D12Device::CreateImage()
			{
				return Result();
			}

			Result D12Device::CreateImageView()
			{
				return Result();
			}

		}
	}
}