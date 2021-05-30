#include <exedra.h>
#include <glm/glm.hpp>

class Demo : public exedra::Application {
public:
	void Init(int _width, int _height, const std::string& title) override;

protected:
	void Update() override;

private:
	exedra::ecs::Scene scene;
	exedra::res::Shader shader;
	exedra::res::ModelTexture whiteTex;
};