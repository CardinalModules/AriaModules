#pragma once

using namespace rack;
extern Plugin* pluginInstance;



//////////////////////////////// Decorative

// These require a standard <3-shaped screwdriver, provided complimentary with every purchasee. 
struct AriaScrew : SvgScrew {
	AriaScrew() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/screw.svg")));
	}
};

// My personal brand, featuring the Cool S.
struct AriaSignature : SvgWidget {
	AriaSignature() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/signature.svg")));
	}
};



//////////////////////////////// Jacks

// Input jacks are always lit yellow.
struct AriaJackIn : SVGPort {
	AriaJackIn() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/jack-in.svg")));
	}
};

// This output jack is always lit pink.
struct AriaJackOut : SVGPort {
	AriaJackOut() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/jack-out.svg")));
	}
};

// This output jack has a transparent ring, to display a light behind it. 
struct AriaJackTransparent : SVGPort {
	AriaJackTransparent() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/jack-transparent.svg")));
	}
};

/////////////// Old style jack lights (Split and Merge, Darius) - TODO: Rework them to use the new ones.

// This is the light that goes behind transparent jacks. Add it before adding the jack.
// Taken from the component library, I don't fully understand how it works.
// TODO: clean this up to remove any dependency on the component library.
// Also, I can most likely merge the light and the widget into one single component (cf. LEDButton)
template <typename TBase = GrayModuleLightWidget>
struct TOutputLight : TBase {
	TOutputLight() {
		this->addBaseColor(nvgRGB(0xfc, 0xae, 0xbb));
	}
};
typedef TOutputLight<> OutputLight;

template <typename TBase = GrayModuleLightWidget>
struct TInputLight : TBase {
	TInputLight() {
		this->addBaseColor(nvgRGB(0xff, 0xcc, 0x03));
	}
};
typedef TInputLight<> InputLight;

// Set it 0.2mm to the bottom right of the 8.2mm component, or just all centered
template <typename TBase>
struct AriaJackLight : TBase {
	AriaJackLight() {
		this->box.size = app::mm2px(math::Vec(7.8, 7.8));
	}
};


// New style jack lights. Those don't need to be offset. TODO: replace the old ones and lose the "new" qualifier.
struct AriaNewJackLight : app::ModuleLightWidget {
	AriaNewJackLight() {
		this->box.size = app::mm2px(math::Vec(8.0, 8.0));
		this->bgColor = nvgRGB(0x0e, 0x69, 0x77);
		this->borderColor = nvgRGB(0x0e, 0x69, 0x77);
	}
	
	void drawLight(const widget::Widget::DrawArgs& args) override {
		float radius = std::min(this->box.size.x, this->box.size.y) / 2.0;
		nvgBeginPath(args.vg);
		nvgCircle(args.vg, radius, radius, radius);

		// Background
		if (this->bgColor.a > 0.0) {
			nvgFillColor(args.vg, this->bgColor);
			nvgFill(args.vg);
		}

		// Foreground
		if (this->color.a > 0.0) {
			nvgFillColor(args.vg, this->color);
			nvgFill(args.vg);
		}

		// Border
		if (this->borderColor.a > 0.0) {
			nvgStrokeWidth(args.vg, app::mm2px(0.2));
			nvgStrokeColor(args.vg, this->borderColor);
			nvgStroke(args.vg);
		}
	}
};

struct AriaNewInputLight : AriaNewJackLight {
	AriaNewInputLight() {
		this->addBaseColor(nvgRGB(0xff, 0xcc, 0x03));
	}
};

struct AriaNewOutputLight : AriaNewJackLight {
	AriaNewOutputLight() {
		this->addBaseColor(nvgRGB(0xfc, 0xae, 0xbb));
	}
};




//////////////////////////////// Switches

// 5.00mm switch. Yellow when lit.
struct AriaPushButton500 : SvgSwitch {
	AriaPushButton500() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-500-off.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-500-on.svg")));
	}
};

struct AriaPushButton500Momentary : SvgSwitch {
	AriaPushButton500Momentary() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-500-off.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-500-on.svg")));
		momentary = true;
	}
};

// 7.00mm switch. Samesies.
struct AriaPushButton700 : SvgSwitch {
	AriaPushButton700() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-700-off.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-700-on.svg")));
	}
};

struct AriaPushButton700Momentary : SvgSwitch {
	AriaPushButton700Momentary() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-700-off.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-700-on.svg")));
		momentary = true;
	}
};

// 8.20mm switch. Yes.
struct AriaPushButton820 : SvgSwitch {
	AriaPushButton820() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-820-off.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-820-on.svg")));
	}
};

struct AriaPushButton820Momentary : SvgSwitch {
	AriaPushButton820Momentary() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-820-off.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/pushbutton-820-on.svg")));
		momentary = true;
	}
};

// Rocker siwtch, horizontal. Left is default
struct AriaRockerSwitchHorizontal800 : SvgSwitch {
	AriaRockerSwitchHorizontal800() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/rocker-switch-800-l.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/rocker-switch-800-r.svg")));
	}
};

struct AriaRockerSwitchVertical800 : SvgSwitch {
	AriaRockerSwitchVertical800() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/rocker-switch-800-u.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/rocker-switch-800-d.svg")));
	}
};


//////////////////////////////// Knobs

struct AriaKnob820 : app::SvgKnob {
	AriaKnob820() {
		minAngle = -0.83 * M_PI;
		maxAngle = 0.83 * M_PI;
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/knob-820.svg")));
	}
};


struct AriaKnob820Transparent : app::SvgKnob {
	AriaKnob820Transparent() {
		minAngle = -0.83 * M_PI;
		maxAngle = 0.83 * M_PI;
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/components/knob-820-transparent.svg")));
	}
};
