#include "Buffer.h"

#include <glad/glad.h>

namespace OGRenderer {

    /*
    * ====================
    * === VertexBuffer ===
    * ====================
    */
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {

        return new VertexBuffer(vertices, size);
    }

    VertexBuffer::VertexBuffer(float* vertices, uint32_t size) {

        glCreateBuffers(1, &m_ID);
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_ID);
    }

    void VertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    }

    void VertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /*
    * ====================
    * === IndexBuffer ====
    * ====================
    */
    IndexBuffer* IndexBuffer::Create(uint32_t* indicies, uint32_t size) {

        return new IndexBuffer(indicies, size);
    }

    IndexBuffer::IndexBuffer(uint32_t* indices, uint32_t count)
        : m_Count(count)
    {
        glCreateBuffers(1, &m_ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer() {
        glDeleteBuffers(1, &m_ID);
    }

    void IndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    }

    void IndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}