#pragma once

#include <vector>
#include <memory>

#include "InitStructs/SwapchainDesc.hpp"
#include "Result.hpp"

namespace te
{
	namespace gr
	{
		class Image;
		class ImageView;
		class Device;

		class Swapchain
		{
		protected:
			std::vector<std::unique_ptr<Image>> m_Images;
			std::vector<std::unique_ptr<ImageView>> m_ImageViews;

			Device* m_Device;

			SwapchainDesc m_Desc;

		public:
			Swapchain(Device* Dev, SwapchainDesc& Desc);
			virtual ~Swapchain();

			virtual void Present() = 0;
			virtual void Resize() = 0;
			virtual std::int32_t GetCurrentIndex() = 0;

			const Image* GetImage(std::int32_t Index);
			const ImageView* GetImageView(std::int32_t Index);

		};
	}
}