#include "fileloader.h"
#include <nfd.h>
#include "src/logging/log.h"
#include "src/resources/model.h"
#include "src/resources/modeltexture.h"
#include "src/graphics/window.h"
#include "src/gui/transformwindow.h"
#include "src/ecs/scene.h"

namespace exedra {
	namespace utils {
		void FileLoader::Load3dObject() {

            nfdchar_t* outPath;
            //std::string extensions = resources::Model::GetImportExtensions();
            //std::replace(extensions.begin(), extensions.end(), ';', ',');

            nfdfilteritem_t filterItem[1] = { { "3D Model", "obj,fbx" } };
            nfdresult_t result = NFD_OpenDialog(&outPath, filterItem, 1, NULL);
            if (result == NFD_OKAY)
            {
                LOG_CORE_TRACE("Successfully opened file: {0}", outPath);

                res::Model loadedModel(outPath);
                loadedModel.CreateEntities();

                NFD_FreePath(outPath);
            }
            else if (result == NFD_CANCEL) {
                LOG_CORE_TRACE("File Dialog Canceled");
            }
            else {
                LOG_CORE_ERROR("Error while opening file: {0}", NFD_GetError());
            }
		}

        void FileLoader::LoadTexture() {
            nfdchar_t* outPath;
            nfdfilteritem_t filterItem[1] = { { "Image files", "jpg,jpeg,png" } };
            nfdresult_t result = NFD_OpenDialog(&outPath, filterItem, 1, NULL);
            if (result == NFD_OKAY)
            {
                LOG_CORE_TRACE("Successfully opened file: {0}", outPath);

                {
                    using namespace res;
                    ModelTexture tex(outPath, aiTextureType_DIFFUSE);
                    tex.Bind();
                }

                NFD_FreePath(outPath);
            }
            else if (result == NFD_CANCEL) {
                LOG_CORE_TRACE("File Dialog Canceled");
            }
            else {
                LOG_CORE_ERROR("Error while opening file: {0}", NFD_GetError());
            }
        }

        std::string FileLoader::GetFolder() {
            nfdchar_t* outPath;
            nfdresult_t result = NFD_PickFolder(&outPath, NULL);
            if (result == NFD_OKAY) {
                LOG_CORE_TRACE("Successfully opened folder: {0}", outPath);
                std::string result = std::string(outPath);
                return result;
            }
            else if (result == NFD_CANCEL) {
                LOG_CORE_TRACE("File Dialog Canceled");
            }
            else {
                LOG_CORE_ERROR("Error while opening Folder: {0}", NFD_GetError());
            }

            return std::string();
        }
	}
}