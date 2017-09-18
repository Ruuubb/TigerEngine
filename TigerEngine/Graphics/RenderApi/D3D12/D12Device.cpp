#include "../Adapter.hpp"

#include "D12Device.hpp"
#include "D12Adapter.hpp"
#include "D12Queue.hpp"
#include "D12Swapchain.hpp"

#include "../InitStructs/QueueDesc.hpp"

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

			D12Device::~D12Device()
			{
				Shutdown();
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

			Result D12Device::CreateVertexBuffer(VertexBuffer** CreatedVertexBuffer)
			{
				return Result();
			}

			Result D12Device::CreateIndexBuffer(IndexBuffer** CreatedIndexBuffer)
			{
				return Result();
			}

			Result D12Device::CreateConstantBuffer(ConstantBuffer** CreatedConstantBuffer)
			{
				return Result();
			}

			Result D12Device::CreateCommandPool(CommandPool** CreatedCommandPool)
			{
				return Result();
			}

			Result D12Device::CreateCommandBuffer(CommandBuffer** CreatedCommandBuffer)
			{
				return Result();
			}

			Result D12Device::CreateQueue(QueueDesc& Desc, Queue** CreatedQueue)
			{
				*CreatedQueue = new D12Queue();
				static_cast<D12Queue*>(*CreatedQueue)->Initialize(this, Desc);

				return Result();
			}

			Result D12Device::CreateFence(Fence** CreatedFence)
			{
				return Result();
			}

			Result D12Device::CreateSwapchain(SwapchainDesc& Desc, Swapchain** CreatedSwapchain)
			{
				*CreatedSwapchain = new D12Swapchain(this, Desc);
				static_cast<D12Swapchain*>(*CreatedSwapchain)->Initialize();

				return Result();
			}

			Result D12Device::CreateRenderPass(RenderPass** RenderPass)
			{
				return Result();
			}

			Result D12Device::CreatePipeline(Pipeline** CreatedPipeline)
			{
				return Result();
			}

			Result D12Device::CreateFrameBuffer(FrameBuffer** CreatedFrameBuffer)
			{
				return Result();
			}

			Result D12Device::CreateImage(Image** CreatedImage)
			{
				return Result();

			}

			Result D12Device::CreateImageView(ImageView** CreatedImageView)
			{
				return Result();
			}

			ID3D12Device* D12Device::GetDevice() const
			{
				return m_Device;
			}

		}
	}
}