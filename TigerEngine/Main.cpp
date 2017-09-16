#include <iostream>

#include "Graphics/RenderApi/D3D12/D12Device.hpp"
#include "Graphics/RenderApi/D3D12/D12Instance.hpp"

int main()
{
	std::vector<std::unique_ptr<te::gr::Adapter>> Adapters;
	te::gr::Device* Dev;

	te::gr::d12::D12Instance I;
	I.EnumerateAdapters(Adapters);
	I.CreateDevice(Adapters[0].get(), &Dev);

	std::unique_ptr<te::gr::Device> RenderDevice;
	RenderDevice = std::unique_ptr<te::gr::Device>(Dev);


	std::cin.get();
	return 0;
}