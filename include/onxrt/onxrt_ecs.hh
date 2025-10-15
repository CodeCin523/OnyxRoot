#ifndef __ONXRT_ECS_HH__
#define __ONXRT_ECS_HH__

#include "onxrt_def.hh"

#include <limits>

namespace onxrt {
    template<typename ECS_EntityIndex, typename ECS_Component>
    class ECS_System {
    public:
        using Entity = ECS_EntityIndex;
        using Component = ECS_Component;

        static constexpr fast_u32 s_pageLength = 1024;
        static constexpr auto s_invalidEntity = std::numeric_limits<Entity>::max();

    private:
        Component *m_pComp;
        Entity m_compCount;
        Entity m_compLength;

        Entity *m_pPage[s_pageLength];
        Entity m_pageCount;
        Entity m_pageLength;

        Entity *m_pCtP;     // Comp to Page
        fast_u32 *m_PtC;    // Page to Comp

    public:
        bool insert(Entity index, Component comp) {
            // if(index < 0) return false;

            fast_u32
                entityPage = index / s_pageLength,
                entityBlock = index % s_pageLength;
            
            // Find in page.
            fast_u32 pageIndex = 0;
            for(; pageIndex < m_pageCount; ++pageIndex) {

            }

            // Find in comp.
            if(m_compCount >= m_compLength) {

            }
        }
        bool remove(Entity index) {

        }

        void process();
    };
};

#endif