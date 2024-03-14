#include "Camera.hpp"

namespace gps {


    //Camera constructor
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
        //TODO
        this->cameraPosition = cameraPosition;
        this->cameraTarget = cameraTarget;
        this->cameraUpDirection = cameraUp;
        if (glm::length(cameraFrontDirection) == 0.0f) {
            cameraFrontDirection = glm::normalize(cameraPosition - cameraTarget);
        }

        if (glm::length(cameraRightDirection) == 0.0f) {
            cameraRightDirection = glm::normalize(glm::cross(cameraUp, cameraFrontDirection));
        }
        
    }

    //return the view matrix, using the glm::lookAt() function
    glm::mat4 Camera::getViewMatrix() {
        //TODO

        return glm::lookAt(cameraPosition, cameraTarget, this->cameraUpDirection);
    }

    //update the camera internal parameters following a camera move event
    void Camera::move(MOVE_DIRECTION direction, float speed) {
        //TODO
        if (direction == MOVE_FORWARD) {
            cameraPosition -= cameraFrontDirection * speed;
        }
        if (direction == MOVE_BACKWARD) {
            cameraPosition += cameraFrontDirection * speed;
        }
         if (direction == MOVE_RIGHT) {
            cameraPosition += cameraRightDirection * speed;
        }
         if (direction == MOVE_LEFT) {
            cameraPosition -= cameraRightDirection * speed;
        }
    }

    //update the camera internal parameters following a camera rotate event
    //yaw - camera rotation around the y axis
    //pitch - camera rotation around the x axis
    void Camera::rotate(float pitch, float yaw) {
        cameraFrontDirection = glm::normalize(glm::vec3(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
        ));
        //TODO
    }
}
