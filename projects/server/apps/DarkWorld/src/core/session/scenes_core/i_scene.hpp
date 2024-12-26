// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw
{
class net_session;
class engine;
class session_properties;
class gui;

class i_scene
{
  public:
    i_scene();

    void update(std::shared_ptr<engine> engine);
    void render(std::shared_ptr<net_session> net_session, std::shared_ptr<session_properties> session_properties);

    virtual void update_derived(std::shared_ptr<engine> engine) = 0;
    virtual void render_derived(std::shared_ptr<net_session> net_session,
                                std::shared_ptr<session_properties> session_properties) = 0;

  protected:
    auto get_gui()
    {
        return gui_;
    }

  private:
    std::shared_ptr<gui> gui_;
};
} // namespace dw
