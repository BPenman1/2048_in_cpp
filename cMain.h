#pragma once
#include "wx/wx.h"
#include "wx/grid.h"

class cMain : public wxFrame {

public:
	cMain();
	~cMain();

public:
	wxButton* m_btn_w = nullptr;
	wxButton* m_btn_s = nullptr;
	wxButton* m_btn_a = nullptr;
	wxButton* m_btn_d = nullptr;

	wxButton* m_btn_new = nullptr;
	wxButton* m_btn_quit = nullptr;

	wxButton* m_btn_robot = nullptr;

	wxListBox* text_box = nullptr;

	//grid
	wxButton* m_btn_0_0 = nullptr;
	wxButton* m_btn_1_0 = nullptr;
	wxButton* m_btn_2_0 = nullptr;
	wxButton* m_btn_3_0 = nullptr;

	wxButton* m_btn_0_1 = nullptr;
	wxButton* m_btn_1_1 = nullptr;
	wxButton* m_btn_2_1 = nullptr;
	wxButton* m_btn_3_1 = nullptr;

	wxButton* m_btn_0_2 = nullptr;
	wxButton* m_btn_1_2 = nullptr;
	wxButton* m_btn_2_2 = nullptr;
	wxButton* m_btn_3_2 = nullptr;

	wxButton* m_btn_0_3 = nullptr;
	wxButton* m_btn_1_3 = nullptr;
	wxButton* m_btn_2_3 = nullptr;
	wxButton* m_btn_3_3 = nullptr;




	void on_down_clicked(wxCommandEvent& evt);

	void on_up_clicked(wxCommandEvent& evt);

	void on_left_clicked(wxCommandEvent& evt);

	void on_right_clicked(wxCommandEvent& evt);

	void new_game(wxCommandEvent& evt);

	void quit_game(wxCommandEvent& evt);

	void robot(wxCommandEvent& evt);


	std::pair<int, int> gen_open_pos();
	void add_tile();
	void clear_game();
	void print_grid();
	void move_numbers(int dir);
	void commit_move(int dir);
	void commands(int input);
	void win_lose_condition();

	int grid_matrix[4][4];
	int temp_matrix[4][4];

	int find_best_move();
	

	wxDECLARE_EVENT_TABLE();

};