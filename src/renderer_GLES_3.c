#if defined(SDL_GPU_DYNAMIC_GLES_3)
    #if defined(SDL_GPU_DYNAMIC_GLES_2)
        #include "gl2stub.c"
        // #include "gl2stub.h"
    #endif
    #include "gl3stub.c"
    // #include "gl3stub.h"
#endif


#include "SDL_gpu_GLES_3.h"
#include "SDL_gpu_RendererImpl.h"


#if defined(SDL_GPU_DISABLE_GLES) || defined(SDL_GPU_DISABLE_GLES_3)

// Dummy implementations
GPU_Renderer* GPU_CreateRenderer_GLES_3(GPU_RendererID request) {return NULL;}
void GPU_FreeRenderer_GLES_3(GPU_Renderer* renderer) {}

#else

// Most of the code pulled in from here...
#define SDL_GPU_USE_GLES
#define SDL_GPU_GLES_MAJOR_VERSION 3
#define SDL_GPU_GLSL_VERSION 300

#define SDL_GPU_USE_BUFFER_PIPELINE
#define SDL_GPU_SKIP_ENABLE_TEXTURE_2D
#define SDL_GPU_ASSUME_SHADERS
#define SDL_GPU_ASSUME_CORE_FBO
// TODO: Make this dynamic because GLES 3.1 supports it
#define SDL_GPU_DISABLE_TEXTURE_GETS

//#ifndef GLES_3_INT_DEF
//#define GLES_3_INT_DEF
#include "renderer_GL_common.inl"
#include "renderer_shapes_GL_common.inl"
//#endif

GPU_Renderer* GPU_CreateRenderer_GLES_3(GPU_RendererID request)
{
    GPU_Renderer* renderer;
    #ifdef SDL_GPU_DYNAMIC_GLES_3
    #ifdef SDL_GPU_DYNAMIC_GLES_2
    if(!gl2stubInit())
        return NULL;
    #endif
    if(!gl3stubInit())
        return NULL;
    #endif

    renderer = (GPU_Renderer*)SDL_malloc(sizeof(GPU_Renderer));
    if(renderer == NULL)
        return NULL;

    memset(renderer, 0, sizeof(GPU_Renderer));

    renderer->id = request;
    renderer->id.renderer = GPU_RENDERER_GLES_3;
    renderer->shader_language = GPU_LANGUAGE_GLSLES;
    renderer->min_shader_version = 100;
    renderer->max_shader_version = SDL_GPU_GLSL_VERSION;
    
    renderer->default_image_anchor_x = 0.5f;
    renderer->default_image_anchor_y = 0.5f;
    
    renderer->current_context_target = NULL;
    
    renderer->impl = (GPU_RendererImpl*)SDL_malloc(sizeof(GPU_RendererImpl));
    memset(renderer->impl, 0, sizeof(GPU_RendererImpl));
    SET_COMMON_FUNCTIONS(renderer->impl);

    return renderer;
}

void GPU_FreeRenderer_GLES_3(GPU_Renderer* renderer)
{
    if(renderer == NULL)
        return;

    SDL_free(renderer->impl);
    SDL_free(renderer);
}


#endif
