class PositionMenu extends PopupMenu
{
	protected TextListboxWidget m_LstPositionList;
	protected EditBoxWidget m_TxtSelectedX;
	protected EditBoxWidget m_TxtSelectedY;
	protected EditBoxWidget m_TxtCurrentX;
	protected EditBoxWidget m_TxtCurrentY;
	protected ButtonWidget m_TeleportButton;
	protected ButtonWidget m_CancelButton;

	autoptr map< string, vector > Positions = new map< string, vector >;

    protected bool m_bOverCurrentPos;

	void PositionMenu()
	{
	    m_bOverCurrentPos = false;

        Positions.Insert( "Stonington", "7044.00 0 1813.77" );
		Positions.Insert( "Ocenville", "10218.56 0 4881.16" );
		Positions.Insert( "Hazelands", "4564.50 0 2671.11" );
		Positions.Insert( "Paris Island", "2997.00 0 3984.89" );
		Positions.Insert( "Airfield", "5635.00 0 3655.57" );
		Positions.Insert( "Devils Eye", "6649.00 0 3487.41" );
		Positions.Insert( "Starks Castle", "5846.50 0 2450.39" );
		Positions.Insert( "Prison", "5541.50 0 737.22" );
		Positions.Insert( "Kushville", "7515.50 0 3910.82" );
		Positions.Insert( "Milo", "6505.00 0 3950.36" );
		Positions.Insert( "Sunset Cross", "6607.50 0 6355.71" );
		Positions.Insert( "Asheville", "7296.50 0 2571.51" );
		Positions.Insert( "Warren Cove", "7078.50 0 5408.78" );
		Positions.Insert( "Greenville", "4669.00 0 1503.47" );
		Positions.Insert( "Sandy Bay", "5407.00 0 7595.42" );
		Positions.Insert( "Sheep Island", "12088.50 0 3873.28" );
		Positions.Insert( "Smallville", "10351.00 0 4401.30" );
		Positions.Insert( "Groots Hill", "7538.00 0 4596.99" );
		Positions.Insert( "Pauls View", "9486.00 0 3754.67" );
		Positions.Insert( "Stonington Harbor", "6890.50 0 1527.99" );
		Positions.Insert( "Industrial", "6731.94 0 2297.35" );
		Positions.Insert( "Suburbs South", "7418.50 0 1584.55" );
		Positions.Insert( "Suburbs North", "6460.50 0 2072.52" );
		Positions.Insert( "Camp Eagle", "8835.50 0 3738.15" );
		Positions.Insert( "Camp Wolf", "5464.00 0 1022.50" );
		Positions.Insert( "Scouts Camp", "4943.50 0 2102.55" );
		Positions.Insert( "Fishers Camp", "10339.00 0 5588.46" );
		Positions.Insert( "Portland", "6032.50 0 14911.56" );
		Positions.Insert( "Georgestown", "4741.00 0 4416.31" );
		Positions.Insert( "Mount Katahdin", "7185.50 0 11636.86" );
		Positions.Insert( "Westbrook", "3275.00 0 6334.69" );
		Positions.Insert( "Old Town", "1920.00 0 9073.86" );
		Positions.Insert( "Area 42", "13422.00 0 9849.62" );
		Positions.Insert( "Camp Bear", "8882.50 0 5991.85" );
		Positions.Insert( "RCFI", "3762.50 0 8862.15" );
		Positions.Insert( "Mine", "11259.50 0 2275.72" );
		Positions.Insert( "Crotch Island", "10715.00 0 3111.54" );
		Positions.Insert( "Temple", "367.089 48.2792 723.626" );
	}

	void ~PositionMenu()
	{
	}

	void Init()
	{
		m_LstPositionList = TextListboxWidget.Cast( layoutRoot.FindAnyWidget("tls_ppp_pm_positions_list") );
		m_TxtSelectedX = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("pnl_ppp_pm_selected_x_value") );
		m_TxtSelectedY = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("pnl_ppp_pm_selected_y_value") );
		m_TxtCurrentX = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("pnl_ppp_pm_current_x_value") );
		m_TxtCurrentY = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("pnl_ppp_pm_current_y_value") );
		m_TeleportButton = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btn_ppp_pm_teleport") );
		m_CancelButton = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btn_ppp_pm_cancel") );

        for ( int nPosition = 0; nPosition < Positions.Count(); nPosition++ )
        {
            m_LstPositionList.AddItem( Positions.GetKey( nPosition ), NULL, 0 );
        }
	}

	override void OnShow()
	{
        vector player_pos = GetGame().GetPlayer().GetPosition();

        m_TxtCurrentX.SetText( player_pos[0].ToString() );
		m_TxtCurrentY.SetText( player_pos[2].ToString() );
	}

	override void OnHide()
	{

	}

	override bool OnMouseEnter(Widget w, int x, int y)
	{
        if ( w == m_TxtCurrentX || w == m_TxtCurrentY )
        {
            m_bOverCurrentPos = true;
        }

		return false;
	}

	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
        if ( w == m_TxtCurrentX || w == m_TxtCurrentY )
        {
            m_bOverCurrentPos = false;
        }

		return false;
	}

	override bool OnKeyPress( Widget w, int x, int y, int key )
	{
		if ( m_bOverCurrentPos )
		{
            m_TxtSelectedX.SetText( "" );
            m_TxtSelectedY.SetText( "" );
		}

		return false;
	}

	override bool OnClick( Widget w, int x, int y, int button )
	{
		if ( w == m_TeleportButton )
		{
		    float pos_x = 0;
            float pos_y = 0;

		    if( ( m_TxtSelectedX.GetText() != "" ) && ( m_TxtSelectedY.GetText() != "" ) )
		    {
	            pos_x = m_TxtSelectedX.GetText().ToFloat();
                pos_y = m_TxtSelectedY.GetText().ToFloat();
		    }
		    else if( ( m_TxtCurrentX.GetText() != "" ) && ( m_TxtCurrentY.GetText() != "" ) )
		    {
                pos_x = m_TxtCurrentX.GetText().ToFloat();
                pos_y = m_TxtCurrentY.GetText().ToFloat();
		    }
		    else
		    {
		        PlayerBase oPlayer = GetGame().GetPlayer();
		        oPlayer.MessageStatus( "Invalid teleportation position!" );

		        return true;
		    }

			vector vPlayerPos;
			vPlayerPos[0] = pos_x;
			vPlayerPos[2] = pos_y;

			vPlayerPos = SnapToGround( vPlayerPos );

			GetGame().GetPlayer().SetPosition( vPlayerPos );

			return true;
		}

		return false;
	}

	override bool OnItemSelected( Widget w, int x, int y, int row, int column, int oldRow, int oldColumn )
	{
		vector position = "0 0 0";

		if( !Positions.Find( GetCurrentPositionName(), position ) )
		{
			position = "0 0 0";
		}

		m_TxtSelectedX.SetText( position[0].ToString() );
		m_TxtSelectedY.SetText( position[2].ToString() );

		return true;
	}

	string GetCurrentPositionName()
	{
		if ( m_LstPositionList.GetSelectedRow() != -1 )
		{
			string position_name;
			m_LstPositionList.GetItemText( m_LstPositionList.GetSelectedRow(), 0, position_name );
			return position_name;
		}

		return "";
	}
}