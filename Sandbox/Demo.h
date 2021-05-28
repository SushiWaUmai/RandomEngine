#include <exedra.h>
#include <glm/glm.hpp>

class Demo : public exedra::Application {
private:
	exedra::ecs::Scene scene;
	exedra::resources::Shader shader;
public:
	void Init(int _width, int _height, const std::string& title) override;

protected:
	void Update() override;
};