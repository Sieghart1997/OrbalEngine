#pragma once

#include <vector>

#include "opengl/shaderprogram.h"

#include "../maths/vec.h"

struct Vertex{
    vec3 vertice;
    vec2 uv;
    vec3 normal;

    Vertex() = default;
    Vertex(const vec3 &vertice, const vec2 &uv, const vec3 &normal) : vertice(vertice), uv(uv), normal(normal) {}

    friend QDebug operator<<(QDebug dbg, const Vertex &vertex);
};


class Mesh{

    std::string o_name;
    std::vector<vec3> m_Vertices;
    std::vector<vec2> m_UVs;
    std::vector<vec3> m_Normals;
    std::vector<unsigned int> m_Vertices_indexlist;
    std::vector<unsigned int> m_UVs_indexlist;
    std::vector<unsigned int> m_Normals_indexlist;

public:

    Mesh(const char *filepath);

    Mesh(const std::vector<vec3> &vertices,
         const std::vector<unsigned int> &vertices_indexlist,
         const std::vector<vec2> &uvs,
         const std::vector<unsigned int> &uvs_indexlist,
         const std::vector<vec3> &normals,
         const std::vector<unsigned int> &normals_indexlist);

    Mesh(const std::vector<vec3> &vertices,
         const std::vector<unsigned int> &vertices_indexlist);

    Mesh(const std::vector<vec3> &vertices,
         const std::vector<unsigned int> &vertices_indexlist,
         const std::vector<vec3> &normals,
         const std::vector<unsigned int> &normals_indexlist);

public:

    void getVertexList(std::vector<Vertex> &vertexList);
    void getVertexList(std::vector<Vertex> &vertexList, std::vector<unsigned short> &elements);

    inline const char* getMeshName() const { return o_name.c_str(); }
    inline unsigned long getN_Vertices() const { return m_Vertices.size(); }
    inline unsigned long getN_UVs() const { return m_UVs.size(); }
    inline unsigned long getN_Normals() const { return m_Normals.size(); }
    inline unsigned long getN_Vertices_index() const { return m_Vertices_indexlist.size(); }
    inline unsigned long getN_UVs_index() const { return m_UVs_indexlist.size(); }
    inline unsigned long getN_Normals_index() const { return m_Normals_indexlist.size(); }

private:

    bool load_obj(const char* filepath);

};
