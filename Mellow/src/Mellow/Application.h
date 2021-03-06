#pragma once

#include "Core.h"

#include "Window.h"
#include "Mellow/Layer.h"
#include "Mellow/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Mellow/ImGui/ImGuiLayer.h"



namespace Mellow
{
	class MELLOW_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	//To be defined in Client
	Application* CreateApplication();
	
}
