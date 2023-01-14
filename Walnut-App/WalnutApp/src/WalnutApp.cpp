#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/implot/implot.h"

#include "Walnut/gpop/reproduction.h"
#include "Walnut/gpop/selection.h"

class ExampleLayer : public Walnut::Layer
{
public:
	int current_T = 20;

	virtual void OnUIRender() override
	{
		ImGui::Begin("Settings");

		static int N = 1000;
		ImGui::InputInt("population size", &N);

		static float p = 0.5f;
		ImGui::InputFloat("initial A allele frequency", &p, 0.001f, 1.0f, "%.4f");

		static int T = 20;
		
		ImGui::InputInt("number of generations", &T);

		static float vec4a[4] = { 0.5f, 1.0f, 0.5f, 0.44f };
		ImGui::InputFloat3("wAA wAa waa", vec4a);

		static float x[1000000], y[1000000];
		
		if (ImGui::Button("Simulate"))
		{
			// Simulation
			std::vector<float> selection_weights = {vec4a[0], vec4a[1], vec4a[2]};
			float allele_freq = p;
			current_T = T;

			for (int i = 0; i < T; i++) {
				x[i] = i;
				y[i] = allele_freq;
				auto reproduction_genoms = reproduction(N, allele_freq);
				auto selection_allele_freq = selection(reproduction_genoms, selection_weights);
				allele_freq = selection_allele_freq[0];
			}
		}

		ImGui::End();

		// Graph
		ImGui::Begin("Graph");
		ImPlot::SetNextAxesLimits((double)0.0, (double)20.0, (double)0.0, (double)1.0);

		if (ImPlot::BeginPlot("Allele Frequency", ImVec2(-1, -1))) {
			
			ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
			ImPlot::PlotLine("freq allele", x, y, current_T);
			ImPlot::EndPlot();
		}

		ImGui::End();

		/* ImPlot Example ---
		static float xs1[1001], ys1[1001];
		for (int i = 0; i < 1001; ++i) {
			xs1[i] = i * 0.001f;
			ys1[i] = 0.5f + 0.5f * sinf(50 * (xs1[i] + (float)ImGui::GetTime() / 10));
		}
		static double xs2[20], ys2[20];
		for (int i = 0; i < 20; ++i) {
			xs2[i] = i * 1 / 19.0f;
			ys2[i] = xs2[i] * xs2[i];
		}
		if (ImPlot::BeginPlot("Line Plots", ImVec2(-1, -1))) {
			ImPlot::SetupAxes("x", "y");
			ImPlot::PlotLine("f(x)", xs1, ys1, 1001);
			ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
			ImPlot::PlotLine("g(x)", xs2, ys2, 20);
			ImPlot::EndPlot();
		}

		ImPlot::ShowDemoWindow();
		--- */
	}
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Walnut Example";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	
	/* Top menu bar
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	*/
	
	return app;
}