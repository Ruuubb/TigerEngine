#include <iostream>

#include "Graphics/RenderApi/Device.hpp"
#include "Graphics/RenderApi/D3D12/D12Instance.hpp"

#include "Graphics/RenderApi/Queue.hpp"
#include "Graphics/RenderApi/InitStructs/QueueDesc.hpp"

#include "Graphics/RenderApi/Swapchain.hpp"
#include "Graphics/RenderApi/InitStructs/SwapchainDesc.hpp"

int main()
{
	std::vector<std::unique_ptr<te::gr::Adapter>> Adapters;
	te::gr::Device* Dev;

	te::gr::d12::D12Instance I;
	I.EnumerateAdapters(Adapters);
	I.CreateDevice(std::move(Adapters[0]), &Dev);

	std::unique_ptr<te::gr::Device> RenderDevice;
	RenderDevice = std::unique_ptr<te::gr::Device>(Dev);

	te::gr::Queue* Queue;
	te::gr::QueueDesc Qd;
	Qd.Priority = te::gr::QueuePriority::Normal;
	Qd.Type = te::gr::QueueType::General;

	RenderDevice->CreateQueue(Qd, &Queue);

	te::gr::Swapchain* SwapC;
	te::gr::SwapchainDesc SwapDesc;
	RenderDevice->CreateSwapchain(SwapDesc, &SwapC);


	std::cin.get();
	return 0;
}