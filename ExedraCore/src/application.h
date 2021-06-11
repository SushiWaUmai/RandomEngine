#pragma once
#include "src/core.h"
#include "src/graphics/window.h"
#include "src/input/inputhandler.h"

namespace exedra {
	class EXD_API Application {
	public:
		Application() = default;
		virtual ~Application();
		virtual void Init(int _width, int _height, const std::string& title);
		virtual void Run();

		inline input::InputHandler& GetInput() { return window.GetInput(); }

	private:
		graphics::Window window;
		void InitGLFW() const;
		void InitGLAD() const;

	protected:
		std::string projectPath;
		virtual void Update();
	};
}