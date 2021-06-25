#pragma once
//namespace Hazel {
//#ifdef HZ_PLATFORM_WINDOWS
	
    //fucntion some place else to return the pointer to application for us
	extern Hazel::Application* Hazel::CreateApplication();   

	int main(int argc, char** argv)
	{
		Hazel::Log::Init();
		HZ_CORE_WARN("Initialized Log!"); //Hazel::Log::GetCoreLogger()->warn("Initialized Log!");
		int a = 5; 
		HZ_INFO("Hello! Var={0}", a); //Hazel::Log::GetClientLogger()->info("Hello!");

		auto app = Hazel::CreateApplication();
		app->Run();
		delete app;
		return 0;
	}
//#endif
//}
