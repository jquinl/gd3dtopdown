#include "GD3Dvisual_obstacle.hpp"

GD3Dvisual_obstacle::GD3Dvisual_obstacle()
{
}

GD3Dvisual_obstacle::~GD3Dvisual_obstacle()
{
}

void GD3Dvisual_obstacle::_bind_methods()
{
	//Signals
	
	ClassDB::bind_method(D_METHOD("on_enter_obstacle"), &GD3Dvisual_obstacle::on_enter_obstacle);
	ClassDB::bind_method(D_METHOD("on_exit_obstacle"), &GD3Dvisual_obstacle::on_exit_obstacle);

	ClassDB::bind_method(D_METHOD("get_auto_invisible"), &GD3Dvisual_obstacle::get_auto_invisible);
	ClassDB::bind_method(D_METHOD("set_auto_invisible", "auto_invisible"), &GD3Dvisual_obstacle::set_auto_invisible);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "auto_invisible"), "set_auto_invisible", "get_auto_invisible");

	ADD_SIGNAL(MethodInfo("visual_disappear_signal", PropertyInfo(Variant::RID, "object_rid"), PropertyInfo(Variant::OBJECT, "object")));
	ADD_SIGNAL(MethodInfo("visual_appear_signal", PropertyInfo(Variant::RID, "object_rid"), PropertyInfo(Variant::OBJECT, "object")));
}

void GD3Dvisual_obstacle::on_enter_obstacle()
{
	if (auto_invisible) { this->set_visible(false); }

	emit_signal("visual_disappear_signal", get_rid(), this);
}
void GD3Dvisual_obstacle::on_exit_obstacle()
{
	if (auto_invisible) { this->set_visible(true); }

	emit_signal("visual_appear_signal", get_rid(), this);
}

bool GD3Dvisual_obstacle::get_auto_invisible() const { return auto_invisible; }
void GD3Dvisual_obstacle::set_auto_invisible(const bool var){auto_invisible = var; }
