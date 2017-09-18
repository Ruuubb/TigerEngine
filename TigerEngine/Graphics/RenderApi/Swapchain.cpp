#include "Swapchain.hpp"
#include "Image.hpp"
#include "ImageView.hpp"

namespace te
{
	namespace gr
	{
		Swapchain::Swapchain(Device* Dev, SwapchainDesc& Desc) :
			m_Device(Dev),
			m_Desc(Desc)
		{

		}

		Swapchain::~Swapchain()
		{

		}

		const Image* Swapchain::GetImage(std::int32_t Index)
		{
			return m_Images[Index].get();
		}

		const ImageView* Swapchain::GetImageView(std::int32_t Index)
		{
			return m_ImageViews[Index].get();
		}

	}
}