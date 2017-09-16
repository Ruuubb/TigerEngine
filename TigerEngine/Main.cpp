#include <iostream>

#include "Graphics/RenderApi/D3D12/D12Device.hpp"
#include "Graphics/RenderApi/D3D12/D12Instance.hpp"

int main()
{
	std::vector<std::unique_ptr<te::gr::Adapter>> Adapters;

	te::gr::d12::D12Instance I;
	I.EnumerateAdapters(Adapters);
	I.CreateDevice(Adapters[0].get());


	std::cin.get();
	return 0;
}